// Copyright Saber Hossseini, year 2020

#include "igg_image/io_strategies/ppm_strategy.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name,
                          const ImageData& img_data) const {
  std::ofstream image_file(file_name, std::ofstream::out);
  if (!image_file) {
    std::cerr << "Cannot open file!" << std::endl;
    return false;
  }// end if

  image_file << "P3 " << std::endl; // P3 stand for color image
  image_file << img_data.cols << " " << "\n";
  image_file << img_data.rows << " " << "\n";
  image_file << img_data.max_val << " " << "\n";

  std::vector<std::vector<int>> data = img_data.data;
  int size_channel = data[0].size();

  for (int i = 0; i < size_channel; ++i) {
    image_file << data[0][i] << " " << data[1][i] << " "
               << data[2][i] << " ";

    if (!(i % img_data.cols)  && i != 0)
      image_file << "\n";
  }// end for

  image_file.close();

  return true;
} // end PpmIoStrategy::Write


ImageData PpmIoStrategy::Read(const std::string& file_name) const {


  ImageData image_data;
  std::ifstream image_file(file_name, std::ofstream::in);

  if (!image_file) {
    std::cout << "Cannot open file!" << std::endl;
    std::exit(EXIT_FAILURE);
  }// end if

  // read the header
  std::string version;
  image_file >> version;

  if (!version.compare("P3 "))
  {
    std::cerr << "Invalid image format (must be 'P3')" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::string comment{};
  std::getline(image_file, comment);
  std::getline(image_file, comment);
  std::cout << "Comment inside file: " << comment << std::endl;

  unsigned int width, height, maxvalue;

  image_file >> width >> height >> maxvalue;

  image_data.max_val = maxvalue;
  image_data.rows = height;
  image_data.cols = width;

  std::vector<int> red  (width * height, 0);
  std::vector<int> green(width * height, 0);
  std::vector<int> blue (width * height, 0);

  int idx = 0;
  while (image_file >> red[idx] >> green[idx] >> blue[idx]) {

    idx++;

  }

  image_data.data = {red, green, blue};


  return image_data;
}// end PpmIoStrategy::Read

}  // namespace igg
