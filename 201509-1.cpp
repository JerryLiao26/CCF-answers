#include <iostream>

int divide(int *arr, int num) {
  int part = 1;
  int temp = arr[0];
  
  for (int i = 1; i < num; ++i) {
    if (arr[i] != temp) {
      part++;
      temp = arr[i];
    } 
  }
  return part;
}

int main(int argc, char *argv[])
{
  int num = 0;
  std::cin >> num;

  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }

  std::cout << divide(arr, num) << std::endl;

  return 0;
}
