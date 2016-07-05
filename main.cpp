//------------------------------------------------------------------------------
// main.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "command_controller.h"
#include "error.h"
#include <exception>

//------------------------------------------------------------------------------
// Main Function
// Entry point to program. Handles commandline arguments first, fetches
// Commands and executes them afterwards.
// @return Returns correct exit code.
//
int main(int argc, char* argv[])
{
  // prevent bad_alloc exceptions from crashing the program
  try
  {
    CommandController controller;

    // handle commandline arguments
    int exit = controller.parseArgs(argc, argv);
    if (exit != 0)
    {
      return exit;
    }

    // main method that fetches and executes Commands
    return controller.fetchCommand();
  }
  catch (std::bad_alloc& e)
  {
    Error::show(Error::OUT_OF_MEMORY);
    return 1;
  }
}