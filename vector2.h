//------------------------------------------------------------------------------
// vector2.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef VECTOR2_H
#define VECTOR2_H

//------------------------------------------------------------------------------
// Vector2 Class
// Class to save x and y position of object on the board.
//
class Vector2
{
protected:

  int x_;
  int y_;

public:

  //----------------------------------------------------------------------------
  // Constructor
  // Creates object initialized to 0 or with specfic values.
  //
  Vector2();
  Vector2(const int x, const int y);

  //----------------------------------------------------------------------------
  // Equality Operator
  // Check vectors for equality.
  // @param other The other vector.
  // @return Returns whether vectors are the same.
  //
  bool operator==(const Vector2& other) const;

  //----------------------------------------------------------------------------
  // Moveby Method
  // Adds the given parameter to the current position.
  // @param dx Number to add to x.
  // @param dy Number to add to y.
  //
  void moveby(const int dx, const int dy);

  //----------------------------------------------------------------------------
  // Getter Method
  //
  int getX() const;
  int getY() const;

  //----------------------------------------------------------------------------
  // Setter Methods
  //
  void set(const int x, const int y);
};

#endif // VECTOR2_H