//------------------------------------------------------------------------------
// command_register.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef REGISTERCOMMAND_H
#define REGISTERCOMMAND_H

#include "command_factory.h"
#include <string>

using std::string;

class Command;


//------------------------------------------------------------------------------
// CommandRegister Class
// Dummy class for having a derived class being registered in the
// corresponding cpp file.
//
template<typename T>
class CommandRegister
{
private:

  //----------------------------------------------------------------------------
  // Type Creation Method
  // @returns Returns a new type of the class provided as template.
  //
  static Command* createType() { return new T; }

public:

  //----------------------------------------------------------------------------
  // Constructor
  // Registers a command name for a class.
  // Create instance of this class at top of every class derived from Command.
  // @param name The name of the command the class is registered for.
  //
  CommandRegister(const string& name)
  {
    CommandFactory::registerDerivedClass(name, &createType);
  }
};

#endif // REGISTERCOMMAND_H