#include <iostream>

int find_mid(int* arr, int num)
{
  for (int i = 0; i < num; ++i) {
    // Record numbers
    int s_num = 0;
    int l_num = 0;
    // Comparison
    for (int j = 0; j < num; ++j) {
      if (arr[i] < arr[j]) {
        l_num += 1;
      }
      else if (arr[i] > arr[j]) {
        s_num += 1;
      }
    }
    if (l_num == s_num) {
      return arr[i];
    }
  }
  return -1; 
}

int main(int argc, char *argv[])
{
  int num;
  std::cin >> num;

  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }
  std::cout << find_mid(arr, num);

  return 0;
}
