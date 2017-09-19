#include <iostream>

void sell(int num, bool seat[20][5]) {
  int count = 0;
  // Continue line numbers
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 5; j++) {
      if (seat[i][j] == false) {
        count++;
      }
      else if (seat[i][j] != false) {
        count = 0;
      }
      if (count == num) {
        for (int x = j-num+1; x <= j; x++) {
          seat[i][x] = true; // Sell tickets
          std::cout << i*5+x+1 << " "; // Output number
        }
        std::cout << '\n';
        count = 0;
        return;
      }
    }
    count = 0;
  }

  // Not cotinue
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 5; j++) {
      if (seat[i][j] == false) {
        seat[i][j] = true;
        std::cout << i*5+j+1 << " ";
        count++;
      }
      if (count == num) {
        std::cout << '\n';
        count = 0;
        return;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int num = 0;
  std::cin >> num;

  bool seat[20][5] = {false};
  for (int i = 0; i < num; i++) {
    int n = 0;
    std::cin >> n;
    sell(n, seat);
  }

  return 0;
}
