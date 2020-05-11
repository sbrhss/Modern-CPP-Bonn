// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include "igg_image/io_strategies/png_strategy.h"

#include <string>
#include <vector>

namespace igg {

bool PngIoStrategy::Write(const std::string& file_name,
                          const ImageData& data) const {
  png::image<png::rgb_pixel> image(data.cols /* width */,
                                   data.rows /* height */);
  for (int r = 0; r < data.rows; ++r) {
    for (int c = 0; c < data.cols; ++c) {
      int idx = r * data.cols + c;
      image[r][c] = png::rgb_pixel(
          data.data[0][idx], data.data[1][idx], data.data[2][idx]);
    }
  }
  image.write(file_name);
  return true;
}

ImageData PngIoStrategy::Read(const std::string& file_name) const {
  png::image<png::rgb_pixel> image(file_name);
  ImageData image_data;
  image_data.max_val = 255;
  image_data.cols = image.get_width();
  image_data.rows = image.get_height();
  std::vector<int> red(image_data.rows * image_data.cols, 0);
  std::vector<int> green(image_data.rows * image_data.cols, 0);
  std::vector<int> blue(image_data.rows * image_data.cols, 0);
  for (int r = 0; r < image_data.rows; ++r) {
    for (int c = 0; c < image_data.cols; ++c) {
      int idx = r * image_data.cols + c;
      red[idx] = image[r][c].red;
      green[idx] = image[r][c].green;
      blue[idx] = image[r][c].blue;
    }
  }
  image_data.data = {red, green, blue};
  return image_data;
}

}  // namespace igg
