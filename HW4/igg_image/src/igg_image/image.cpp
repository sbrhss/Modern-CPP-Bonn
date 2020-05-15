#include "image.h"
#include <iostream>

namespace igg {

// in upscale and downscale I am using different ways to initilize a vector!

void Image::DownScale(int scale) {
	// Create the downscaled image
	int downscaled_rows = rows_ / scale;
	int downscaled_cols = cols_ / scale;

	std::vector<Pixel> downscaled_image;
	downscaled_image.reserve(downscaled_rows * downscaled_cols);


	// Iterate over image
	for (int i = 0; i < rows_; i += scale) {
		for (int j = 0; j < cols_; j += scale) {
			downscaled_image.emplace_back(data_.at(i * cols_ + j));
		}
	}

	rows_ = downscaled_rows;
	cols_ = downscaled_cols;
	data_ = downscaled_image;
}



void Image::UpScale(int scale) {

	// Create the upscaled image
	int upscaled_rows = rows_ * scale;
	int upscaled_cols = cols_ * scale;
	std::vector<Pixel> upscaled_image(upscaled_rows * upscaled_cols, {0, 0, 0});


	// Iterate over the image
	for (int i = 0; i < rows_; i++) {
		int row_jump = i * scale;
		for (int j = 0; j < cols_; j++) {
			int col_jump = j * scale;
			// Fill values for upscaled image
			for (int u = 0; u < scale; u++) {
				for (int v = 0; v < scale; v++) {
					upscaled_image[(row_jump + u)*upscaled_cols + col_jump + v] = data_[i * cols_ + j];
				}
			}
		}
	}

	rows_ = upscaled_rows;
	cols_ = upscaled_cols;
	data_ = upscaled_image;
}

bool Image::ReadFromDisk(const std::string& file_name) {

	// strategy_ptr_ is nullptr
	if (!strategy_ptr_)
	{
		std::cout << "The strategy has not set yet!" << std::endl;
		return false;
	}
	else {
		const ImageData& image = strategy_ptr_->Read(file_name);

		if (image.data.empty()) {
			std::cout << "Could not find the file, or the file is empty!" << std::endl;
			return false;
		}
		else {
			std::cout << "Image file found :)" << std::endl;
			rows_ = image.rows;
			cols_ = image.cols;
			max_val_ = image.max_val;
			std::vector<std::vector<int>> img_data = image.data;

			int size_channel = img_data[0].size();
			for (int i = 0; i < size_channel; ++i) {
				Pixel pixel{img_data[0][i], img_data[1][i], img_data[2][i]};
				data_.emplace_back(pixel);
			}

			return true;
		}

	}


}

bool Image::WriteToDisk(const std::string& file_name) {

	// strategy_ptr_ is nullptr
	if (!strategy_ptr_) {
		return false;
	}
	else {
		ImageData image;
		image.rows = rows_;
		image.cols = cols_;
		image.max_val = max_val_;

		std::vector<int> red(rows_ * cols_, 0);
		std::vector<int> green(rows_ * cols_, 0);
		std::vector<int> blue(rows_ * cols_, 0);

		for (int idx = 0, size = data_.size(); idx < size; idx++) {
			red[idx] = data_[idx].red;
			green[idx] = data_[idx].green;
			blue[idx] = data_[idx].blue;
		}
		image.data = {red, green, blue};

		bool success = strategy_ptr_->Write(file_name, image);

		if (success)
			std::cout << "File has been written successfully :)" << std::endl;
		else
			std::cout << "Something went wrong in write process!" << std::endl;
		return true;
	}
}

} //igg namespace