#include <iostream>

int calc_diff(int a, int b) {
  if (a - b < 0) {
    return b - a;
  }
  else {
    return a - b;
  }
}

int biggest_diff(int *arr, int num) {
  int diff = 0;
  
  for (int i = 0; i < num - 1; ++i) {
    int temp = calc_diff(arr[i], arr[i+1]);
    if (temp > diff) {
      diff = temp;
    }
  }
  return diff;
}

int main(int argc, char *argv[])
{
  int num = 0;
  std::cin >> num;

  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }

  std::cout << biggest_diff(arr, num) << std::endl;

  return 0;
}
