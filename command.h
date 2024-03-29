//------------------------------------------------------------------------------
// command.h
//
// Group: -, study assistant -
//
// Authors: Tutors
//------------------------------------------------------------------------------
//

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Game;

class Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Command(const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Command& operator=(const Command& original);

    //--------------------------------------------------------------------------
    // Name of this command
    //
    std::string command_name_;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    Command(std::string name);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Command();

    //--------------------------------------------------------------------------
    // Executing Method
    // Executes the command.
    // @param board The board where action should be performed on.
    // @param params Possible parameters needed for the execution.
    // @return Integer representing the success of the action.
    //
    virtual int execute(Game& board, std::vector<std::string>& params) = 0;

    //--------------------------------------------------------------------------
    // Getter Methods
    //
    const std::string& getName() const;
};

#endif //COMMAND_H_INCLUDED