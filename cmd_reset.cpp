//------------------------------------------------------------------------------
// cmd_reset.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "cmd_reset.h"
#include "game.h"
#include "error.h"

//------------------------------------------------------------------------------
CommandRegister<CommandReset> CommandReset::reg("reset");

//------------------------------------------------------------------------------
CommandReset::CommandReset() : Command("reset")
{
}

//------------------------------------------------------------------------------
CommandReset::~CommandReset()
{
}

//------------------------------------------------------------------------------
int CommandReset::execute(Game &board, std::vector<std::string> &params)
{
  if (params.size() != 1)
  {
    Error::show(Error::WRONG_PARAMETER_COUNT);
    return 0;
  }

  if (!board.isLoaded())
  {
    Error::show(Error::NO_MAZE_LOADED);
    return 0;
  }

  board.reset();
  return 0;
}