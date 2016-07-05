//------------------------------------------------------------------------------
// command_factory.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <map>
#include <string>
#include <memory>

using std::string;
using std::map;
using std::unique_ptr;


class Command;


// adapted from stackoverflow:
// http://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-
// objects-from-a-string-holding-their-class-name

// defining custom map type to store strings and Commands
typedef map<string, Command*(*)()> CommandsMap;


//------------------------------------------------------------------------------
// CommandFactory Class
// Class to register Commands and create instances of them.
//
class CommandFactory
{

private:
  static unique_ptr<CommandsMap> commands_;

public:

  //----------------------------------------------------------------------------
  // Instance Creation Method
  // Creates an instance from a class's name.
  // @param name A string containing the name of the Command.
  // 
  static Command* createInstance(const string& name);
  
  //----------------------------------------------------------------------------
  // Register Derived Class Method
  // Registers a class name for creating instances later on.
  // @param name A string with the name of the Command.
  //
  static void registerDerivedClass(const string& name,
                                   Command*(*derivedClass)());
};

#endif // COMMANDFACTORY_H