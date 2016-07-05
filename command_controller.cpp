//------------------------------------------------------------------------------
// command_controller.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "command_controller.h"
#include "command_factory.h"
#include "command.h"
#include "invalid_command_exception.h"
#include "invalid_move_exception.h"
#include "game.h"
#include "helper.h"
#include "error.h"
#include <iostream>
#include <sstream>
#include <memory>


using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::string;
using std::istringstream;
using std::vector;
using std::unique_ptr;

//------------------------------------------------------------------------------
CommandController::CommandController()
{
}

//------------------------------------------------------------------------------
int CommandController::parseArgs(int argc, char* argv[])
{
  string load_filename = "";
  string save_filename = "";

  if (argc > 5 || argc == 4 || argc == 2)
  {
    Error::show(Error::WRONG_USAGE);
    return 2;
  }

  for (int parse_count = 1; parse_count < argc; parse_count += 2)
  {
    string token = argv[parse_count];
    string arg = argv[parse_count + 1];

    if (token == "-m" && arg != "-s" && load_filename == "")
    {
      load_filename = arg;
    }
    else if (token == "-s" && arg != "-m" && save_filename == "")
    {
      save_filename = arg;
    }
    else
    {
      Error::show(Error::WRONG_USAGE);
      return 2;
    }
  }

  // ensure that if there is a autosavefilename set, that
  // the load command can already autosave at end
  if (save_filename != "")
  {
    current_game_.setAutoSaveFilename(save_filename);
  }

  if (load_filename != "")
  {
    current_game_.load(load_filename);
  }
  return 0;
}

//------------------------------------------------------------------------------
int CommandController::fetchCommand()
{
  while (true)
  {
    try
    {
      cout << "sep> ";
      vector<string> parameters;
      bool eof = getLine(parameters);

      if (parameters.size() != 0)
      {
        // ignore case in commands
        string lowercase_command = Helper::toLowerCase(parameters[0]);

        // quit command
        if (lowercase_command == "quit")
        {
          if (parameters.size() == 1)
          {
            cout << "Bye!" << endl;
            return 0;
          }
          else
          {
            Error::show(Error::WRONG_PARAMETER_COUNT);
            continue;
          }
        }

        // every other command
        unique_ptr<Command>
            command(CommandFactory::createInstance(lowercase_command));
        command->execute(current_game_, parameters);
      }

      if (eof)
      {
        // close program after eof
        // (last command gets executed)
        return 0;
      }
    }
    catch (std::bad_alloc& out_of_memory)
    {
      Error::show(Error::OUT_OF_MEMORY);
      return 1;
    }
    catch (InvalidCommandException& invalid_command)
    {
      cout << invalid_command.what() << endl;
    }
    catch (InvalidMoveException& invalid_move)
    {
      cout << invalid_move.what() << endl;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
bool CommandController::getLine(vector<string>& tokens)
{
  string input;
  getline(cin, input);

  string part;
  istringstream iss(input);
  while (iss >> part)
  {
    tokens.push_back(part);
  }

  return cin.eof();
}