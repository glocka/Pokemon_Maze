//------------------------------------------------------------------------------
// cmd_show.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "cmd_show.h"
#include "game.h"
#include "error.h"

//------------------------------------------------------------------------------
CommandRegister<CommandShow> CommandShow::reg("show");

//------------------------------------------------------------------------------
CommandShow::CommandShow() : Command("show")
{
}

//------------------------------------------------------------------------------
CommandShow::~CommandShow()
{
}

//------------------------------------------------------------------------------
int CommandShow::execute(Game& board, std::vector<std::string>& params)
{
  if (params.size() > 2 || params.size() < 1)
  {
    Error::show(Error::WRONG_PARAMETER_COUNT);
    return 0;
  }

  if (params.size() == 2 && params[1]!= "more")
  {
    Error::show(Error::WRONG_PARAMETER);
    return 0;
  }

  if (!board.isLoaded())
  {
    Error::show(Error::NO_MAZE_LOADED);
    return 0;
  }

  if (params.size() == 2 && params[1] == "more")
  {
    board.showMore();
  }
  else
  {
    board.show();
  }

  return 0;
}