//------------------------------------------------------------------------------
// direction.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "direction.h"

using std::map;
using std::string;

//------------------------------------------------------------------------------
const Direction Direction::INVALID_DIRECTION = Direction(0, 0, ' ');

//------------------------------------------------------------------------------
const map<const string, const Direction> Direction::directions_ =
 { { "u", Direction(0, -1, 'u')}, { "d", Direction(0, 1, 'd') },
   { "r", Direction(1, 0, 'r') }, { "l", Direction(-1, 0, 'l') },
   { "up", Direction(0, -1, 'u')}, { "down", Direction(0, 1, 'd') },
   { "right", Direction(1, 0, 'r') }, { "left", Direction(-1, 0, 'l') } };

//------------------------------------------------------------------------------
Direction::Direction(const int x, const int y, const char shorthand)
  : Vector2(x, y), shorthand_(shorthand)
{
}

//------------------------------------------------------------------------------
const Direction& Direction::getDirection(const string& direction)
{
  map<const string, const Direction>::const_iterator iterator =
      directions_.find(direction);
  if (iterator == directions_.end())
  {
    return Direction::INVALID_DIRECTION;
  }

  return iterator->second;
}

//------------------------------------------------------------------------------
char Direction::getShortHand() const
{
  return shorthand_;
}