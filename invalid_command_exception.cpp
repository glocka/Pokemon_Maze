//------------------------------------------------------------------------------
// invalid_command_exception.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "invalid_command_exception.h"
#include "error.h"

//------------------------------------------------------------------------------
InvalidCommandException::InvalidCommandException()
{
}

//------------------------------------------------------------------------------
const char* InvalidCommandException::what() const noexcept
{
  return Error::UNKNOWN_COMMAND;
}