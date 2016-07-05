//------------------------------------------------------------------------------
// cmd_move.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H

#include "command.h"
#include "command_register.h"

//------------------------------------------------------------------------------
// CommandMove derived by class Command
// Command for moving by using english words (up, right, down, left)
// as directions.
//
class CommandMove : public Command
{
private:

  //----------------------------------------------------------------------------
  // Object that registers Command in its constructor.
  //
  static CommandRegister<CommandMove> reg;

public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandMove();

  //----------------------------------------------------------------------------
  // Destructor
  //
  virtual ~CommandMove();

  //----------------------------------------------------------------------------
  // Execute Method
  // Performs the Command move by interpreting the given string as direction.
  // @param board The current board.
  // @param params Contains the parameters entered in the console.
  //            1. Parameter: Name of the command.
  //            2. Parameter: String with the direction.
  // @return int Returns 0 if finished.
  //
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif // COMMANDMOVE_H