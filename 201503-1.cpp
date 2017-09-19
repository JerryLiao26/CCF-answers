#include <iostream>

#define BOUND 1000

void rotate(int matrix[BOUND][BOUND], int n, int m) {
  for (int j = m-1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[]) {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  unsigned short matrix[BOUND][BOUND] = {0}; // Important

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];
    }
  }

  for (int j = m-1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }

  // rotate(matrix, n, m);

  return 0;
}
