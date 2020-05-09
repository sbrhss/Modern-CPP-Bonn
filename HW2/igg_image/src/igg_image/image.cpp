#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "image.h"
#include "io_tools.h"


namespace igg {


	const int& Image::at(int rows, int cols) const {
		return Image::data_.at(rows * Image::cols_ + cols);
	}


	int& Image::at(int rows, int cols){
		return Image::data_.at(rows * Image::cols_ + cols);
	}


	bool Image::FillFromPgm (const std::string& file_name){

			io_tools::ImageData dataFromFile = io_tools::ReadFromPgm(file_name);
			if (dataFromFile.data.empty()){
				std::cout << "Cannot find the file! " << std::endl;
				return false;
			}
			else
			{
				std::cout << "File " << file_name << " found :)" << std::endl;
				Image::rows_ = dataFromFile.rows;
				Image::cols_ = dataFromFile.cols;
				Image::data_.assign(dataFromFile.data.begin(), dataFromFile.data.end());
				Image::max_val_ = dataFromFile.max_val;
				return true;
			}
	}

	void Image::WriteToPgm(const std::string& file_name) const{
		   const io_tools::ImageData& dataToFile = io_tools::ImageData{
			Image::rows_,
			Image::cols_,
			Image::max_val_,
			Image::data_
		};
		bool sucess =  io_tools::WriteToPgm(dataToFile, file_name);
		if(sucess){
			std::cout << file_name << " has been written successfull!" << std::endl;
		}
		else{
			std::cout << "An error occured during write, double check the file name." << std::endl;	
		}
	}

	std::vector<float> Image::ComputeHistogram(const int bins) const{
		
		std::vector<float> hist(bins);
		hist.reserve(bins);
		std::fill(hist.begin(), hist.end(), 0);

		for (auto element: Image::data_){
			int bin = (int) (((float)element / Image::max_val_) * bins);
			++hist[bin];
		}
		int total_area = Image::rows() * Image::cols();

		std::transform(hist.begin(), hist.end(), hist.begin(),
               std::bind2nd(std::divides<float>(), total_area));

		return hist;

	}


	void Image::DownScale(int scale) {
    // Create the downscaled image
	    int downscaled_rows = rows_/scale;
	    int downscaled_cols = cols_/scale;
	    std::vector<int> downscaled_image;
	    downscaled_image.reserve(downscaled_rows * downscaled_cols);
	    

	    // Iterate over image
	    for (int i = 0; i < rows_; i+=scale) {
	        for (int j = 0; j < cols_; j+=scale) {
	            downscaled_image.emplace_back(data_[i * cols_ + j]);
	        	}
	    	}

	    rows_ = downscaled_rows;
	    cols_ = downscaled_cols;
	    data_ = downscaled_image;
		}

	void Image::UpScale(int scale) {
    // Create the upscaled image
	    int upscaled_rows = rows_*scale;
	    int upscaled_cols = cols_*scale;
	    std::vector<int> upscaled_image;
	    upscaled_image.reserve(upscaled_rows * upscaled_cols + 1);
	    std::fill(upscaled_image.begin(), upscaled_image.end(), 0);

	    // Iterate over the image
	    for (int i = 0; i < rows_; i++) {
	        int row_jump = i * scale;
	        for (int j = 0; j < cols_; j++) {
	            int col_jump = j*scale;
	            // Fill values for upscaled image
	            for (int u = 0; u < scale; u++) {
	                for (int v = 0; v < scale; v++) {
	                    upscaled_image[(row_jump+u)*upscaled_cols + col_jump + v] = data_[i * cols_ + j];
	                }
	            }
	        }
	    }

	    rows_ = upscaled_rows;
	    cols_ = upscaled_cols;
	    data_ = upscaled_image;
	}


	}// namespace igg