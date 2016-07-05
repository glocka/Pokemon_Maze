//------------------------------------------------------------------------------
// helper.cpp
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#include "helper.h"

using std::string;

//------------------------------------------------------------------------------
bool Helper::isValidFilename(const string &filename)
{
  if (filename.size() > 255)
  {
    return false;
  }

  for (unsigned i = 0; i < filename.size(); i++)
  {
    if((filename[i] >= 'a' && filename[i] <= 'z') ||
       (filename[i] >= 'A' && filename[i] <= 'Z') ||
       (filename[i] >= '0' && filename[i] <= '9') ||
       filename[i] == '.' || filename[i] == '/')
    {
    }
    else
    {
      return false;
    }
  }

  return true;
}

//------------------------------------------------------------------------------
string Helper::toLowerCase(const string &word)
{
  int difference = 'a' - 'A';
  string new_word = "";
  for (char current : word)
  {
    if (current < 'a' && current >= 'A')
    {
      new_word += (char)(current + difference);
    }
    else
    {
      new_word += current;
    }
  }

  return new_word;
}