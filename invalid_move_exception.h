//------------------------------------------------------------------------------
// invalid_move_exception.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef INVALIDMOVEEXCEPTION_H
#define INVALIDMOVEEXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// InvalidMoveExeption Class
// Class to handle invalid move expection.
//
class InvalidMoveException : public std::exception
{
public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  InvalidMoveException();

  //----------------------------------------------------------------------------
  // What Method
  // Gives back the error text for command line.
  // @return Returns the error text.
  //
  virtual const char* what() const noexcept;
};

#endif // INVALIDMOVEEXCEPTION_H