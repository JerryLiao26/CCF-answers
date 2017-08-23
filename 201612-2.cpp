#include <iostream>

#define BOUND 3500

int calc_salary(int after)
{
  int texed = after - BOUND;
  int level[7] = {0, 1500, 4500, 9000, 35000, 55000, 80000};
  double rate[7] = {0.03, 0.1, 0.2, 0.25, 0.30, 0.35, 0.45};

  if (texed > 0) {
    int diff = 0;
    int count = 0;
    while (count < 6) {
      int temp = texed - (level[count+1] - level[count]) * (1 - rate[count]);
      if (temp < 0) {
        break;
      }
      else {
        texed = temp;
        diff = level[count+1];
      }
      count++;
    }
    diff += texed / (1 - rate[count]);
    return diff + BOUND;
  }
  return after;
}

int main(int argc, char *argv[])
{
  int after = 0;
  std::cin >> after;

  std::cout << calc_salary(after);

  return 0;
}
