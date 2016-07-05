//------------------------------------------------------------------------------
// command_controller.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include "game.h"
#include <vector>
#include <string>


using std::vector;
using std::string;

//------------------------------------------------------------------------------
// CommandController Class
// Class to get the input from stdin and parsing the Commands.
//
class CommandController
{
private:

  //----------------------------------------------------------------------------
  // Getline Method
  // Reads line from stdin and splits it into parts.
  // @return vector<string> Returns vector of the parts of the read line.
  //
  bool getLine(vector<string>& input);
  Game current_game_;
public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandController();

  //----------------------------------------------------------------------------
  // Command Fetching Method
  // Reads stdin and executs the right command.
  // @return int Returns 0 if everything is executed correctly.
  //
  int fetchCommand();

  //----------------------------------------------------------------------------
  // Commandline Input Parsing Method
  // Handles commandline inputs.
  // @param argc Number of Arguments the program was started with
  // @param argv Array of the seperated arguments.
  // @return int Returns 0 if finishes correctly.
  //
  int parseArgs(int argc, char* argv[]);
};

#endif // COMMANDCONTROLLER_H