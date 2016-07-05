//-----------------------------------------------------------------------------
// game.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "game.h"
#include "helper.h"
#include "cmd_fastmove.h"
#include "field.h"
#include "direction.h"
#include "invalid_move_exception.h"
#include "error.h"
#include <iostream>
#include <fstream>

using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

//------------------------------------------------------------------------------
Game::Game()
{
}

//------------------------------------------------------------------------------
Vector2 Game::findCurrentTeleporter()
{
  char current = getCurrentField();
  if (current >= 'A' && current <= 'Z')
  {
    int letter = current - 'A';
    if (std::get<0>(teleporters[letter]) == player_)
    {
      return std::get<1>(teleporters[letter]);
    }
    else if (std::get<1>(teleporters[letter]) == player_)
    {
      return std::get<0>(teleporters[letter]);
    }
  }

  // should never happen
  return Vector2();
}

//------------------------------------------------------------------------------
bool Game::isValidMaze()
{
  string valid_fields = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghij# ox+<>^v";
  int start_count = 0;
  int finish_count = 0;
  size_t maze_width = maze_[0].size();

  int teleporter[26];
  std::fill(teleporter, teleporter + 26, 0);
  for (size_t row = 0; row < maze_.size(); row++)
  {
    if (maze_[row].size() != maze_width)
    {
      return false;
    }

    if (maze_[row].find_first_not_of(valid_fields) != string::npos)
    {
      return false;
    }

    for (size_t column = 0; column < maze_[row].size(); column++)
    {
      char current = maze_[row][column];
      //check for valid walls
      if (row == 0 || row == maze_.size() - 1 || column == 0
          || column == maze_[row].length() - 1)
      {
        if (current != '#')
        {
          return false;
        }
      }

      // check for start and finish
      if (current == 'o')
      {
        player_.set(column, row);
        start_position_.set(column, row);
        start_count++;
      }
      if (current == 'x')
      {
        finish_count++;
      }

      // check for if there are 2 teleport fields #backtothefuture
      if (current >= 'A' && current <= 'Z')
      {
        int count = teleporter[current - 'A']++;
        if (count == 0)
        {
          std::get<0>(teleporters[current - 'A']) = Vector2(column, row);
        }
        else
        {
          std::get<1>(teleporters[current - 'A']) = Vector2(column, row);
        }
      }
    }
  }

  if (start_count != 1 || finish_count != 1)
  {
    return false;
  }

  for (int tp_count = 0; tp_count < 26; tp_count++)
  {
    if (teleporter[tp_count] != 2 && teleporter[tp_count] != 0)
    {
      return false;
    }
  }
  return true;
}

//------------------------------------------------------------------------------
bool Game::load(const string& load_filename)
{
  if (!Helper::isValidFilename(load_filename))
  {
    Error::show(Error::WRONG_PARAMETER);
    return false;
  }

  // read information from file
  string line;
  string steps;
  string steps_count;

  ifstream load_file;
  load_file.open(load_filename);
  if (!load_file)
  {
    Error::show(Error::CANNOT_OPEN_FILE);
    return false;
  }

  getline(load_file, steps);
  getline(load_file, steps_count);

  while (getline(load_file, line))
  {
    maze_.push_back(line);
  }

  if (maze_.size() == 0)
  {
    Error::show(Error::INVALID_FILE);
    return false;
  }

  if (maze_.back() == "")
  {
    maze_.pop_back();
  }

  // check path for correct characters
  if (steps.find_first_not_of("urdl") != string::npos)
  {
    Error::show(Error::INVALID_FILE);
    return false;
  }

  // check steps for correct charecters
  if (steps_count == ""
      || steps_count.find_first_not_of("0123456789") != string::npos)
  {
    Error::show(Error::INVALID_FILE);
    return false;
  }
  remaining_steps_ = std::stoi(steps_count);


  if (!isValidMaze())
  {
    Error::show(Error::INVALID_FILE);
    return false;
  }

  original_maze_ = maze_;
  original_remaining_steps_ = remaining_steps_;

  try
  {
    fastmove(steps);
  }
  catch (InvalidMoveException& e)
  {
    Error::show(Error::INVALID_PATH);
    return false;
  }

  return true;
}

//------------------------------------------------------------------------------
void Game::save() const
{
  save(auto_save_filename_);
}

//------------------------------------------------------------------------------
void Game::save(const string& save_filename) const
{
  if (save_filename == "")
  {
    return;
  }
  if (!Helper::isValidFilename(save_filename))
  {
    Error::show(Error::WRONG_PARAMETER);
    return;
  }

  // put content into file
  try
  {
    ofstream save_file;
    save_file.open(save_filename);
    save_file.exceptions(ofstream::failbit | ofstream::badbit);

    save_file << steps_ << "" << std::endl;
    save_file << original_remaining_steps_ << "" << std::endl;
    for (size_t row = 0; row < original_maze_.size(); row++)
    {
      // content gets flushed in close of stream(no endl needed)
      save_file << original_maze_[row] << "\n";
    }
    save_file.close();
  }
  catch (ofstream::failure& e)
  {
    Error::show(Error::CANNOT_WRITE_FILE);
  }
}

//------------------------------------------------------------------------------
void Game::reset()
{
  maze_ = original_maze_;
  remaining_steps_ = original_remaining_steps_;
  steps_ = "";
  player_ = start_position_;
  save();
}

//------------------------------------------------------------------------------
void Game::show() const
{
  for (unsigned i = 0; i < getMaze().size(); i++)
  {
    string current = getMaze()[i];
    if (i == (unsigned)player_.getY())
    {
      current[player_.getX()] = '*';
    }
    std::cout << current << std::endl;
  }
}

//------------------------------------------------------------------------------
void Game::showMore() const
{
  std::cout << "Remaining Steps: " << getRemainingSteps()  << std::endl;
  std::cout << "Moved Steps: "<< getSteps()<< std::endl;

  show();
}

//------------------------------------------------------------------------------
void Game::move(const Direction& direction)
{
  if (getCurrentField() == 'x')
  {
    // all steps invalid after reaching finish
    throw InvalidMoveException();
  }

  if(getRemainingSteps() == 0)
  {
    Error::show(Error::NO_STEPS_POSSIBLE);
    reset();
    return;
  }

  Game tmp_game = *this;
  step(tmp_game, direction);
  *this = tmp_game;
  save();
  show();

  if (getCurrentField() == 'x')
  {
    std::cout << "Congratulation! You solved the maze." << std::endl;
  }
}

//------------------------------------------------------------------------------
void Game::fastmove(const string& steps)
{
  if (getCurrentField() == 'x')
  {
    // all steps invalid after reaching finish
    throw InvalidMoveException();
  }

  if(getRemainingSteps() == 0)
  {
    Error::show(Error::NO_STEPS_POSSIBLE);
    reset();
    return;
  }

  Game tmp_game = *this;

  for (char direction : steps)
  {
    string dir;
    dir += direction;
    step(tmp_game, Direction::getDirection(dir));
  }

  *this = tmp_game;
  save();
  show();

  if (getCurrentField() == 'x')
  {
    std::cout << "Congratulation! You solved the maze." << std::endl;
  }
}

//------------------------------------------------------------------------------
void Game::step(Game& tmp_game, const Direction& direction)
{
  if(tmp_game.getRemainingSteps() == 0)
  {
    // will only occur when fastmoving, because
    // remaining steps is checked before calling this method
    throw InvalidMoveException();
  }

  // handle current field
  switch (tmp_game.getCurrentField())
  {
    case Field::ONEWAYUP:
      if (direction.getY() != -1)
        throw InvalidMoveException();
      break;
    case Field::ONEWAYDOWN:
      if (direction.getY() != 1)
        throw InvalidMoveException();
      break;
    case Field::ONEWAYLEFT:
      if (direction.getX() != -1)
        throw InvalidMoveException();
      break;
    case Field::ONEWAYRIGHT:
      if (direction.getX() != 1)
        throw InvalidMoveException();
      break;
  }
  tmp_game.player_.moveby(direction.getX(), direction.getY());

  // handle new field
  switch (tmp_game.getCurrentField())
  {
    case Field::WALL:
      throw InvalidMoveException();

    case Field::ICE:
      while (tmp_game.getCurrentField() == Field::ICE)
      {
        tmp_game.player_.moveby(direction.getX(), direction.getY());

        if (tmp_game.getCurrentField() == Field::WALL)
        {
          tmp_game.player_.moveby(-direction.getX(), -direction.getY());
          break;
        }
      }
    break;
  }

  // handle teleporting
  char current = tmp_game.getCurrentField();
  if (current >= 'A' && current <= 'Z')
  {
    tmp_game.player_ = tmp_game.findCurrentTeleporter();
  }

  // handle bonus / malus
  int bonus = 0;
  if (current >= 'a' && current <= 'e')
  {
    bonus = current - 'a' + 1;
    tmp_game.setCurrentField(' ');
  }
  else if (current >= 'f' && current <= 'j')
  {
    bonus = -(current - 'f' + 1);
  }
  tmp_game.setRemainingSteps(tmp_game.getRemainingSteps() + bonus - 1);


  if (tmp_game.getRemainingSteps() < 0)
  {
    tmp_game.setRemainingSteps(0);
  }

  tmp_game.addSteps(direction.getShortHand());
}

//------------------------------------------------------------------------------
bool Game::isLoaded() const
{
  if (maze_.size() == 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

//------------------------------------------------------------------------------
string Game::getAutoSaveFilename() const
{
  return auto_save_filename_;
}

//------------------------------------------------------------------------------
const vector<string>& Game::getMaze() const
{
  return maze_;
}

//------------------------------------------------------------------------------
char Game::getCurrentField() const
{
  return maze_[player_.getY()][player_.getX()];
}

//------------------------------------------------------------------------------
int Game::getRemainingSteps() const
{
  return remaining_steps_;
}

//------------------------------------------------------------------------------
string Game::getSteps() const
{
  return steps_;
}

//------------------------------------------------------------------------------
void Game::setAutoSaveFilename(const string& save_filename)
{
  auto_save_filename_ = save_filename;
}

//------------------------------------------------------------------------------
void Game::setCurrentField(const char field)
{
  maze_[player_.getY()][player_.getX()] = field;
}

//------------------------------------------------------------------------------
void Game::setRemainingSteps(const int number)
{
  remaining_steps_ = number;
}

//------------------------------------------------------------------------------
void Game::addSteps(const char step)
{
  steps_.push_back(step);
}