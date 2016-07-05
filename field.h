//------------------------------------------------------------------------------
// field.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef FIELD
#define FIELD

//------------------------------------------------------------------------------
// Field Class
// Class for storing name and representation of fields statically.
//
class Field
{
public:
  static const char WALL = '#';
  static const char ICE = '+';
  static const char PATH = ' ';
  static const char START = 'o';
  static const char FINISH = 'x';
  static const char ONEWAYUP = '^';
  static const char ONEWAYDOWN = 'v';
  static const char ONEWAYLEFT = '<';
  static const char ONEWAYRIGHT = '>';
};

#endif // FIELD