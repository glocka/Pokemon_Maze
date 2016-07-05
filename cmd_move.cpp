//------------------------------------------------------------------------------
// cmd_move.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "cmd_move.h"
#include "game.h"
#include "direction.h"
#include "error.h"

//------------------------------------------------------------------------------
CommandRegister<CommandMove> CommandMove::reg("move");

//------------------------------------------------------------------------------
CommandMove::CommandMove() : Command("move")
{
}

//------------------------------------------------------------------------------
CommandMove::~CommandMove()
{
}

//------------------------------------------------------------------------------
int CommandMove::execute(Game& board, std::vector<std::string>& params)
{
  if (params.size() != 2)
  {
    Error::show(Error::WRONG_PARAMETER_COUNT);
    return 0;
  }

  Direction direction = Direction::getDirection(params[1]);
  if (direction == Direction::INVALID_DIRECTION)
  {
    Error::show(Error::WRONG_PARAMETER);
    return 0;
  }

  if (!board.isLoaded())
  {
    Error::show(Error::NO_MAZE_LOADED);
    return 0;
  }

  board.move(direction);
  return 0;
}