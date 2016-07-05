//------------------------------------------------------------------------------
// cmd_reset.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDRESET_H
#define COMMANDRESET_H

#include "command.h"
#include "command_register.h"

//------------------------------------------------------------------------------
// CommandReeset derived by class Command
// Command to reset game.
//
class CommandReset : public Command
{
private:

  //----------------------------------------------------------------------------
  // Object that registers Command in its constructor.
  //
  static CommandRegister<CommandReset> reg;

public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandReset();

  //----------------------------------------------------------------------------
  // Destructor
  //
  virtual ~CommandReset();

  //----------------------------------------------------------------------------
  // Execute Method
  // Performs the Command reset by resetting the remainig steps, the moved path
  // and the player's position.
  // @param board The current board.
  // @param params Contains the parameters entered in the console.
  //            1. Parameter: Name of the command.
  // @return Returns 0 if finished
  //
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif // COMMANDRESET_H