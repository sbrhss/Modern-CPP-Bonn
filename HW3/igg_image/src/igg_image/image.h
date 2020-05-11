// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>
#include "io_strategies/png_strategy.h"

namespace igg {

class Image {
public:
	/// A struct within class Image that defines a pixel.
	struct Pixel {
		int red;
		int green;
		int blue;
	};

	// TODO: fill public interface.
	Image(const IoStrategy& io_strategy): io_strategy_{io_strategy} {}
	Image(int rows, int cols, const IoStrategy& io_strategy): rows_{rows}, cols_{cols}, io_strategy_{io_strategy}
	{
		data_.reserve(cols_ * rows_ * 3); // 3 is because of three color channels
	}

	const Pixel& at(int rows, int cols) const {return data_.at(rows * cols_ + cols);}
	Pixel& at(int rows, int cols) {return data_.at(rows * cols_ + cols);}

	const int& row() const {return rows_;}
	const int& col() const {return cols_;}

	bool ReadFromDisk(const std::string& file_name);
	void WriteToDisk(const std::string& file_name);

	void UpScale(int scale);
	void DownScale(int scale);
private:

	// TODO: add missing private members when needed.

	int rows_ = 0;
	int cols_ = 0;
	int max_val_ = 255;
	std::vector<Pixel> data_;

	const IoStrategy& io_strategy_;
};

}  // namespace igg
