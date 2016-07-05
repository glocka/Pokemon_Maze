//------------------------------------------------------------------------------
// game.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef GAME_H
#define GAME_H

#include "vector2.h"
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;

class Direction;

//------------------------------------------------------------------------------
// Game Class
// Class representing a board and all methods for manipulating it.
//
class Game
{
private:
  // variables for storing the current maze map
  vector<string> maze_;
  int remaining_steps_;
  string steps_;
  tuple<Vector2, Vector2> teleporters[26];

  // variables storing the original map loaded from the file
  vector<string> original_maze_;
  int original_remaining_steps_;


  string auto_save_filename_;

  //----------------------------------------------------------------------------
  // Maze Checking Method
  // Checks if the maze in the given file is valid.
  // @return bool Returns whether maze is valid or not.
  //
  bool isValidMaze();

  //----------------------------------------------------------------------------
  // Step Method
  // Checks if the desired direction the user wants to got to
  // is valid and handles the actions, if the new field is a special field.
  // @param tmp_game A copy of the current game.
  // @param direction The direction the user wants to go to.
  //
  void step(Game& tmp_game, const Direction& direction);

  Vector2 start_position_;
  Vector2 player_;

public:
  //----------------------------------------------------------------------------
  // Constructor
  //
  Game();

  //----------------------------------------------------------------------------
  // Teleporter Finding Method
  // Method to find the corresponding teleporter if the player steps onto one.
  // @return Vector2 Returns the position of the corresponding
  //         teleporter field.
  //
  Vector2 findCurrentTeleporter();

  //----------------------------------------------------------------------------
  // Load Method
  // Loads the content of the given maze file into the appropriate
  // member variables of this class.
  // @param load_filename The name of the file with the maze in it.
  // @return bool Whether the maze was loaded properly.
  //
  bool load(const string& load_filename);

  //----------------------------------------------------------------------------
  // Autosave method
  // Saves file into auto_save_filename_.
  //
  void save() const;

  //----------------------------------------------------------------------------
  // Save Method
  // Saves the current maze with its remaining steps and already
  // taken steps into the given file.
  // @param save_filename The name of the file into which the content
  //        should be saved.
  //
  void save(const string& save_filename) const;

  //----------------------------------------------------------------------------
  // Reset Method
  // Method to reset the game.
  //
  void reset();

  //----------------------------------------------------------------------------
  // Show Method
  // Shows the current maze with all its temporary changes.
  //
  void show() const;

  //----------------------------------------------------------------------------
  // Show More Method
  // Shows the current maze with all its temporary changes and
  // additionally the already taken and the remaining steps.
  //
  void showMore() const;

  //----------------------------------------------------------------------------
  // Move Method
  // Moves Player into the given direction and handles errors that
  // could occour.
  // @param direction The direction which the user wants to go from
  //        the current field.
  //
  void move(const Direction& direction);

  //----------------------------------------------------------------------------
  // Fastmove Method
  // Method to not only perform one, but multiple
  // steps in one Command.
  // @param steps The steps the user wants to take from his current position.
  //
  void fastmove(const string& steps);


  //----------------------------------------------------------------------------
  // Getter Methods
  //
  bool isLoaded() const;
  string getAutoSaveFilename() const;
  const vector<string>& getMaze() const;
  char getCurrentField() const;
  int getRemainingSteps() const;
  string getSteps() const;

  //----------------------------------------------------------------------------
  // Setter Methods
  //
  void setAutoSaveFilename(const string& save_filename);
  void setCurrentField(const char field);
  void setRemainingSteps(int number);
  void addSteps(const char step);
};

#endif // GAME_H