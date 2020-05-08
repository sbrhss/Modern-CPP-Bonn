#include <iostream>
#include "image.h"
#include "io_tools.h"

int main()
{
	igg::Image new_image;
	const std::string file_name = "/home/saber/Desktop/lena.ascii.pgm";
	new_image.FillFromPgm (file_name);

	std::cout << new_image.at(0,0) << std::endl;

	std::vector<float> histogram = new_image.ComputeHistogram(10);
	std::cout << histogram.at(0) << std::endl;
	return 0;
}