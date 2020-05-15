#include <iostream>

int main() {
  int step = 100 * 1000 * sizeof(char);
  int size = step;
  while (true) {

    std::cerr << "size is: " << size << std::endl;
    // allocate memory
    double arr[size];

    arr[0] = 1.0;
    arr[1] += arr[0];

    size += step;
    // in my computer: at the end it is about 8 megabytes 
    std::cout << "Size of array is: " <<sizeof(arr) / 1024 << " Kilo Bytes." << std::endl;
  } 

  return 0;
}