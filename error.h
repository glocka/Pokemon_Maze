//------------------------------------------------------------------------------
// error.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef ERROR_H
#define ERROR_H

#include <iostream>

//------------------------------------------------------------------------------
// Error Class
// Class for storing and outputting error messages.
//
class Error
{
public:
  constexpr static const char* OUT_OF_MEMORY =
      "[ERR] Out of memory.";
  constexpr static const char* WRONG_USAGE =
      "[ERR] Wrong usage: ./basic [-s <filename1>] [-m <filename2>]";
  constexpr static const char* UNKNOWN_COMMAND =
      "[ERR] Unknown command.";
  constexpr static const char* WRONG_PARAMETER_COUNT =
      "[ERR] Wrong parameter count.";
  constexpr static const char* WRONG_PARAMETER =
      "[ERR] Wrong parameter.";
  constexpr static const char* NO_MAZE_LOADED =
      "[ERR] No maze loaded.";
  constexpr static const char* CANNOT_OPEN_FILE =
      "[ERR] File could not be opened.";
  constexpr static const char* INVALID_FILE =
      "[ERR] Invalid file.";
  constexpr static const char* INVALID_PATH =
      "[ERR] Invalid path.";
  constexpr static const char* CANNOT_WRITE_FILE =
      "[ERR] File could not be written.";
  constexpr static const char* INVALID_MOVE =
      "[ERR] Invalid move.";
  constexpr static const char* NO_STEPS_POSSIBLE =
      "[ERR] No more steps possible.";

  //----------------------------------------------------------------------------
  // Method Show
  // Shows error message specified immediatly.
  // @param error The message to show.
  //
  static void show(const char* error);
};

#endif // ERROR_H