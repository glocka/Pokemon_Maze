//------------------------------------------------------------------------------
// cmd_load.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDLOAD_H
#define COMMANDLOAD_H

#include "command.h"
#include "command_register.h"

//------------------------------------------------------------------------------
// CommandLoad Class
// Command to load and parse mazes.
//
class CommandLoad : public Command
{
private:

  //----------------------------------------------------------------------------
  // Object that registers Command in its constructor.
  //
  static CommandRegister<CommandLoad> reg;

public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandLoad();
  
  //----------------------------------------------------------------------------
  // Destructor
  //
  virtual ~CommandLoad();
  
  //----------------------------------------------------------------------------
  // Execute Method
  // Performs the command load by loading the given file.
  // @param board The current board.
  // @param params Contains the parameters entered in the console.
  //            1. Parameter: Name of the command.
  //            2. Parameter: Name of the file.
  // @return int Returns 0 if finished.
  //
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif // COMMANDLOAD_H