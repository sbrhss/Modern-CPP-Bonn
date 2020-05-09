#pragma once

#include <vector>
#include <string>

namespace igg {

class Image {
 public:
	// definition of constructors, default constructor  
 	Image(){}
 	// the second constructor, getting image size, and reserving memory for it.
 	Image(int rows, int cols): rows_{rows}, cols_{cols}
 	{
 		// reserve memory
 		data_.reserve(rows * cols + 1);
 	}
 	// resturn the number of rows
 	int rows() const 
 	{
 		return rows_; 
 	};
 	// return the number of cols
 	int cols() const
 	{
 		return cols_;
 	};

 	// this method will return you the pixel value in the (row, col)
 	const int& at (int row, int col) const;
 	// this method is to change value of a pixel in the (row, col)
 	int& at (int row, int col);

 	bool FillFromPgm (const std::string& file_name);
 	void WriteToPgm (const std::string& file_name) const;
 	
 	std::vector<float> ComputeHistogram(const int bins) const;

    void DownScale(int scale);
	void UpScale(int scale);

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
}; // class image

}  // namespace igg
