//------------------------------------------------------------------------------
// cmd_fastmove.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "cmd_fastmove.h"
#include "game.h"
#include "error.h"

//------------------------------------------------------------------------------
CommandRegister<CommandFastmove> CommandFastmove::reg("fastmove");

//------------------------------------------------------------------------------
CommandFastmove::CommandFastmove() : Command("fastmove")
{
}

//------------------------------------------------------------------------------
CommandFastmove::~CommandFastmove()
{
}

//------------------------------------------------------------------------------
int CommandFastmove::execute(Game& board, std::vector<std::string>& params)
{
  if (params.size() != 2)
  {
    Error::show(Error::WRONG_PARAMETER_COUNT);
    return 0;
  }

  if (params[1].find_first_not_of("urdl") != string::npos)
  {
    Error::show(Error::WRONG_PARAMETER);
    return 0;
  }

  if (!board.isLoaded())
  {
    Error::show(Error::NO_MAZE_LOADED);
    return 0;
  }

  board.fastmove(params[1]);
  return 0;
}