//------------------------------------------------------------------------------
// cmd_load.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "cmd_load.h"
#include "game.h"
#include "error.h"

//------------------------------------------------------------------------------
CommandRegister<CommandLoad> CommandLoad::reg("load");

//------------------------------------------------------------------------------
CommandLoad::CommandLoad() : Command("load")
{
}

//------------------------------------------------------------------------------
CommandLoad::~CommandLoad()
{
}

//------------------------------------------------------------------------------
int CommandLoad::execute(Game& board, std::vector<std::string>& params)
{
  if (params.size() != 2)
  {
    Error::show(Error::WRONG_PARAMETER_COUNT);
    return 0;
  }

  Game game;
  string auto_save = board.getAutoSaveFilename();
  game.setAutoSaveFilename(auto_save);
  if (game.load(params[1]))
  {
    board = game;
  }
  return 0;
}