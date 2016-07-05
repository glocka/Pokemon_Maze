//------------------------------------------------------------------------------
// direction.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef DIRECTION_H
#define DIRECTION_H

#include "vector2.h"
#include <map>
#include <string>

using std::map;
using std::string;

//------------------------------------------------------------------------------
// Direction Class
// Class to check, if the given directen is correct and convert the char/string
// to coordinates.
//
class Direction : public Vector2
{
private:

  //----------------------------------------------------------------------------
  // Map of the allowed directions with coordinates and short notation
  //
  const static map<const string, const Direction> directions_;

  char shorthand_;
  
public:

  const static Direction INVALID_DIRECTION;

  //----------------------------------------------------------------------------
  // Direction Generating Method
  // Checks, if the given direction string is correct and returns
  // Direction-Object (derived from Vector2) representing the direction.
  // @param direction The direction string in move / fastmove command.
  // @return Direction Returns corresponding direction.
  //
  const static Direction& getDirection(const string& direction);

  //----------------------------------------------------------------------------
  // Constructor
  //
  Direction(const int x, const int y, const char shorthand);
  
  //----------------------------------------------------------------------------
  // Getter Methods
  //
  char getShortHand() const;
};

#endif // DIRECTION_H