//------------------------------------------------------------------------------
// command_factory.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "command_factory.h"
#include "invalid_command_exception.h"

//------------------------------------------------------------------------------
unique_ptr<CommandsMap> CommandFactory::commands_;

//------------------------------------------------------------------------------
Command* CommandFactory::createInstance(const std::string &name)
{
  CommandsMap::iterator iterator = commands_->find(name);
  if (iterator == commands_->end())
  {
    throw InvalidCommandException();
  }
  return iterator->second();
}

//------------------------------------------------------------------------------
void CommandFactory::registerDerivedClass(const std::string& name,
                                          Command*(*command)())
{
  // would not work with stack object!!
  // advantage of pointers: can be checked against nullptr
  // and initialized lazily
  if (commands_ == nullptr)
    commands_ = unique_ptr<CommandsMap>(new CommandsMap());

  (*commands_)[name] = command;
}