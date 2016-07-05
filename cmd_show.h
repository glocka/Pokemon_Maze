//------------------------------------------------------------------------------
// cmd_show.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDSHOW_H
#define COMMANDSHOW_H

#include "command.h"
#include "command_register.h"

//------------------------------------------------------------------------------
// CommandShow Class
// Command for showing maze with marked player position.
//
class CommandShow : public Command
{
private:

  //----------------------------------------------------------------------------
  // Object that registers Command in its constructor.
  //
  static CommandRegister<CommandShow> reg;

public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  CommandShow();

  //----------------------------------------------------------------------------
  // Destructor
  //
  virtual ~CommandShow();

  //----------------------------------------------------------------------------
  // Execute Method
  // Performs the Command show by printing the current maze with the position
  // of the player.
  // @param board The current board.
  // @param params Contains the parameters entered in the console.
  //            1. Parameter: Name of the command.
  //            2. Parameter: string which must be "more" so the command shows
  //                  the remaining steps and moved steps in short notation.
  // @return int Returns 0 if finished.
  //
  virtual int execute(Game& board, std::vector<std::string>& params);
};

#endif // COMMANDSHOW_H