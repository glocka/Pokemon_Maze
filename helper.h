//------------------------------------------------------------------------------
// helper.h
//
// Group: Group 13734, study assistant Christoph Maurer
//
// Authors: Gerald Birngruber (1530438)
// Paul Plessing (1530486)
// Richard Sadek (1531352)
//------------------------------------------------------------------------------
//

#ifndef HELPER_H
#define HELPER_H

#include <string>

using std::string;

//------------------------------------------------------------------------------
// Helper Class
// Contains static helper functions to check filenames or convert strings to
// lowercase.
//
class Helper
{
public:

  //----------------------------------------------------------------------------
  // Filename Checking Method
  // Checks if the given filename is valid according to our specifications.
  // @param filename The filename read from the commandline.
  // @return bool Returns true if filename is valid, otherwise false.
  //
  static bool isValidFilename(const string& filename);

  //----------------------------------------------------------------------------
  // Lowercase Conversion Method
  // Changes every character in the given string to lower case letters.
  // @param word A word with upper and lower case letters.
  // @return string The input word with every letter in lower case.
  //
  static string toLowerCase(const string& word);
};

#endif // HELPER_H