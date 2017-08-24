#include <iostream>
#include <algorithm>

int calc_square(int *arr, int start, int len) {
  int height = *std::min_element(arr + start, arr + start + len);
  return height * len;
}

int find_square(int *arr, int num) {
  int square = 0;

  for (int i = 0; i < num; ++i) {
    for (int j = 1; j <= num - i; ++j) {
      int temp = calc_square(arr, i, j);
      if (temp > square) {
        square = temp;
      }
    }
  }
  return square;
}

int main(int argc, char *argv[])
{
  int num = 0;
  std::cin >> num;
  
  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }

  std::cout << find_square(arr, num) << std::endl;

  return 0;
}
