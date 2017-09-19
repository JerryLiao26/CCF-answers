#include <iostream>

#define BOUND 100

struct square {
  int x1, y1, x2, y2;
};

int scan(int zone[BOUND][BOUND]) {
  int num = 0;
  for (int i = 0; i < BOUND; i++) {
    for (int j = 0; j < BOUND; j++) {
      if (zone[i][j] == true) {
        num++;
      }
    }
  }

  return num;
}

void paint(int zone[BOUND][BOUND], square one) {
  for (int i = one.y1; i < one.y2; i++) {
    for (int j = one.x1; j < one.x2; j++) {
      zone[i][j] = true;
    }
  }
}

int main(int argc, char const *argv[]) {
  int num = 0;
  std::cin >> num;

  int zone[BOUND][BOUND] = {false};
  for (int i = 0; i < num; i++) {
    square one;
    std::cin >> one.x1 >> one.y1 >> one.x2 >> one.y2;
    paint(zone, one);
  }
  std::cout << scan(zone) << '\n';

  return 0;
}
