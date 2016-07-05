//------------------------------------------------------------------------------
// cmd_save.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "command.h"
#include "command_register.h"

//------------------------------------------------------------------------------
// CommandSave derived by class Command
// Command for saving mazes.
//
class CommandSave : public Command
{
private:

  //----------------------------------------------------------------------------
  // Object that registers Command in its constructor.
  //
  static CommandRegister<CommandSave> reg;

public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandSave();

  //----------------------------------------------------------------------------
  // Destructor
  //
  virtual ~CommandSave();

  //----------------------------------------------------------------------------
  // Execute Method
  // Performs the Command save by saving a file to the given path.
  // @param board The current board.
  // @param params Contains the parameters entered in the console.
  //            1. Parameter: Name of the command.
  //            2. Parameter: path and filename.
  // @return int Returns 0 if finished.
  //
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif // COMMANDSAVE_H