#include <iostream>
#include <string>
#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"


int main()
{
	const std::string input_file_name = "../data/pbmlib.ascii.ppm";
	const std::string outpu_file_name = "../data/pbmlibOut.ascii.ppm";

	// Time to test PPM strategy
	igg::PpmIoStrategy strategy_ppm;

	// Create ppm image object
	igg::Image image_ppm{strategy_ppm};

	bool success = image_ppm.ReadFromDisk(input_file_name);

	// Read the file
	if (!success) {
		std::cout << "Error reading file" << std::endl;
		return 1;
	}


	
	// Change the image
	for (int i = 0, rows = image_ppm.row(); i < rows; i++) {
		for (int j = 0, cols = image_ppm.col(); j < cols; j++) {
			igg::Image::Pixel p {image_ppm.at(i, j)};
			image_ppm.at(i, j) = igg::Image::Pixel{p.red, p.blue, p.green};
		}
	}


	image_ppm.DownScale(2);
	image_ppm.UpScale(4);

	image_ppm.WriteToDisk(outpu_file_name);

	return 0;
}