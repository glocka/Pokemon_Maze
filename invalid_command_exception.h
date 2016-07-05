//------------------------------------------------------------------------------
// invalid_command_exception.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef INVALIDCOMMANDEXEPTION_H
#define INVALIDCOMMANDEXEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// InvalidCommandException Class
// Class to handle invalid command exceptions.
//
class InvalidCommandException : public std::exception
{
public:

  //----------------------------------------------------------------------------
  // Constructor
  //
  InvalidCommandException();
  
  //----------------------------------------------------------------------------
  // What Method
  // Gives back the error text for command line.
  // @return Returns the error text.
  //
  virtual const char* what() const noexcept;
};

#endif // INVALIDCOMMANDEXEPTION_H