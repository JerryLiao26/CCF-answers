#include <iostream>

bool diff(int a, int b) {
  if (a - b == 1 || b - a == 1) {
    return true;
  }
  return false;
}

int find_pair(int *arr, int num){
  int pair = 0;
  
  for (int i = 0; i < num - 1; ++i) {
    for (int j = i + 1; j < num; ++j) {
      if (diff(arr[i], arr[j])) {
        pair++;
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

  std::cout << find_pair(arr, num) << std::endl;

  return 0;
}
