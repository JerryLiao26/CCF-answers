#include <iostream>

int find_opp(int *arr, int num)
{
  int pair = 0;
  for (int i = 0; i < num; ++i) {
    for (int j = 0; j < num; ++j) {
      if (arr[i] + arr[j] == 0 && arr[i] != 0) {
        pair++;
        arr[i] = 0;
        arr[j] = 0;
      }
    }
  }
  return pair;
}

int main(int argc, char *argv[])
{
  int num = 0;
  std::cin >> num;
  
  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }

  std::cout << find_opp(arr, num) << std::endl;

  return 0;
}

