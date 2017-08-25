#include <iostream>

void calc_date(int year, int day)
{
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int month = 1;

  // Check if leap
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        days[1] += 1;
      }
    }
    else {
      days[1] += 1;
    }
  }

  // Calculate
  for (int i = 0; i < 12; ++i) {
    if (day > days[i]) {
      day -= days[i];
      month++;
    }
    else {
      break;
    }
  }

  // Output
  std::cout << month << '\n' << day << std::endl;
}

int main(int argc, char *argv[])
{
  int year = 0;
  int day = 0;

  std::cin >> year >> day;

  calc_date(year, day);

  return 0;
}
