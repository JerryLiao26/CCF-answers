#include <iostream>

bool find_turn(int form, int mid, int latt) {
  if (form > mid && latt > mid) {
    return true;
  }
  else if (form < mid && latt < mid) {
    return true;
  }
  return false;
}

int count_turn(int *arr, int num) {
  int point = 0;

  for (int i = 1; i < num - 1; ++i) {
    if (find_turn(arr[i-1], arr[i], arr[i+1])) {
      point++;
    }
  }
  return point;
}

int main(int argc, char *argv[])
{
  int num = 0;
  std::cin >> num;

  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }

  std::cout << count_turn(arr, num) << std::endl;
  return 0;
}
