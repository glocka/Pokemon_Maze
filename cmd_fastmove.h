//------------------------------------------------------------------------------
// cmd_fastmove.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDFASTMOVE_H
#define COMMANDFASTMOVE_H

#include "command.h"
#include "command_register.h"

//------------------------------------------------------------------------------
// CommandFastmove Class
// Command for moving by using chars (u, r, d, l) as directions.
//
class CommandFastmove : public Command
{
private:

  //----------------------------------------------------------------------------
  // Object that registers Command in its constructor.
  //
  static CommandRegister<CommandFastmove> reg;

public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandFastmove();

  //----------------------------------------------------------------------------
  // Destructor
  //
  virtual ~CommandFastmove();

  //----------------------------------------------------------------------------
  // Execute Method
  // Performs the Command fastmove by executing the given
  // direction string (e.g. ldur...) character by character.
  // @param board The current board.
  // @param params Contains the parameters entered in the console.
  //            1. Parameter: Name of the command.
  //            2. Parameter: String with the direction in short notation.
  // @return int Returns 0 if finished.
  //
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif // COMMANDLOAD_H