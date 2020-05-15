#include <iostream>
#include <string>
#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"


int main()
{
	const std::string input_file_name = "../data/sars.png";
	const std::string outpu_file_name = "../data/sars_out.png";

	// Time to test PPM strategy
	auto strategyPng = std::make_shared<igg::PngIoStrategy>();

	// Create ppm image object
	igg::Image image_png;

	image_png.SetIoStrategy(strategyPng);

	bool success_read = image_png.ReadFromDisk(input_file_name);

	// Read the file
	if (!success_read) {
		std::cout << "Error while reading file" << std::endl;
		return 1;
	}



	// Change the image
	for (int i = 0, rows = image_png.row(); i < rows; i++) {
		for (int j = 0, cols = image_png.col(); j < cols; j++) {
			igg::Image::Pixel p {image_png.at(i, j)};
			image_png.at(i, j) = igg::Image::Pixel{p.red, p.blue, p.green};
		}
	}


	image_png.DownScale(2);
	image_png.UpScale(4);

	bool success_write = image_png.WriteToDisk(outpu_file_name);

	if (!success_write) {
		std::cout << "Error while writing file" << std::endl;
		return 1;
	}

	return 0;
}