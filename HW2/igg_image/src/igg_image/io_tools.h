// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.
//
// Do not create a cpp file for this file. It is needed to use the library
// lib/libio_tools.so distributed with this repository.

#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace igg {
namespace io_tools {

/// Dummy structure to store relevant image data.
struct ImageData {
  int rows;
  int cols;
  int max_val;
  std::vector<int> data;
};

/// Reads from a pgm image from ascii file. Returns empty ImageData if the path
/// is not found or any errors have occured while reading.
ImageData ReadFromPgm(const std::string& file_name);

/// Write image data into an ascii pgm file. Return true if successful.
bool WriteToPgm(const ImageData& image_data, const std::string& file_name);

}  // namespace io_tools
}  // namespace igg
