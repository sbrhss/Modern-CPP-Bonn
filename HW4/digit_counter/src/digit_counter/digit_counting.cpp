#include <iostream>
#include <cmath>
#include "./digit_counting.hpp"


namespace digitCounting{

double Warp(double number, double factor){


	number += factor;
	number -= factor;
	return number;

}

// Digit counting function definition
  int CountSameSignificantDigits(double a, double b) {
    if (a > 1 && b > 1) {

      std::cout << "Please use numbers between -1 to 1" << std::endl;
      return 0;
    }
    else if (a > 1 || b > 1) {

      return -1;
    }

    int sign_a = a/std::fabs(a);
    int sign_b = b/std::fabs(b);
    // signs are not equal
    if (sign_a != sign_b) {
      return -2;
    }

    a = std::fabs(a);
    b = std::fabs(b);

    int significant_number = 0;
    for (int i = 0; i < 100; i++) {

      double a_times = a * 10.0;
      int num_a = static_cast<int> (a_times);

      double b_times = b * 10.0;
      int num_b = static_cast<int> (b_times);

      if (num_a != num_b) break;

      significant_number++;
      a = a_times - static_cast<double> (num_a);
      b = b_times - static_cast<double> (num_b);
    }

    return significant_number;
  }


}