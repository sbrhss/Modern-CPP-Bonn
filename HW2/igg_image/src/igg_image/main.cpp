#include <iostream>
#include "image.h"
#include "io_tools.h"

int main()
{
	igg::Image new_image;
	const std::string file_name = "/home/saber/Desktop/lena.ascii.pgm";
	new_image.FillFromPgm (file_name);


	std::vector<float> histogram = new_image.ComputeHistogram(10);

	new_image.DownScale(2);
	new_image.WriteToPgm("/home/saber/Desktop/lena2.ascii.pgm");
	return 0;
}