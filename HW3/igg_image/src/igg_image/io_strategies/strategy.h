// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <string>
#include <vector>

namespace igg {

/// Dummy structure to store relevant image data.
struct ImageData {
  int rows;
  int cols;
  int max_val;
  /// Vector of vectors of color data, e.g. {red_vec, green_vec, blue_vec},
  /// where every component, e.g. red_vec is an array of rows * cols numbers and
  /// corresponds to all the values for the red channel.
  std::vector<std::vector<int>> data;
};

class IoStrategy {
 public:
  virtual bool Write(const std::string& file_name,
                     const ImageData& data) const = 0;
  virtual ImageData Read(const std::string& file_name) const = 0;
  virtual ~IoStrategy() {}
};

}  // namespace igg
