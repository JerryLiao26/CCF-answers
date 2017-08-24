#include <iostream>
#include <string>

int add_bit(int digit)
{
  int sum = 0;
  int temp = digit;
  while(temp != 0) {
    sum += temp % 10;
    temp /= 10;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int digit = 0;
  std::cin >> digit;

  std::cout << add_bit(digit) << std::endl;

  return 0;
}
