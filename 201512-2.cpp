#include <iostream>

void matching(int n, int m) {
  int **board;
  int **result; // Store result
  board = new int *[n];
  result = new int *[n];
  for (int i = 0; i < n; ++i) {
    board[i] = new int[m];
    result[i] = new int[m];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> board[i][j];
      result[i][j] = board[i][j];
    }
  }
  // Match lines
  for (int i = 0; i < n; ++i) {
    int len = 1;
    for (int j = 1; j < m; ++j) {
      if (board[i][j] == board[i][j-1]) {
        len++;
      }
      if (j == m-1 && len >= 3 && board[i][j] == board[i][j-1]) {
        for (int x = j; x > j-len ; --x) {
          result[i][x] = 0;
        }
        len = 1;
      }
      else if (len >= 3 && board[i][j] != board[i][j-1]) {
        for (int x = j-1; x > j-len-1; --x) {
          result[i][x] = 0;
        }
        len = 1;
      }
      else if (len < 3 && board[i][j] != board[i][j-1]) {
        len = 1;
      }
    }
  }
  // Match columns
  for (int j = 0; j < m; ++j) {
    int len = 1;
    for (int i = 1; i < n; ++i) {
      if (board[i][j] == board[i-1][j]) {
        len++;
      }
      if (i == n-1 && len >= 3 && board[i][j] == board[i-1][j]) {
        for (int x = i; x > i-len ; --x) {
          result[x][j] = 0;
        }
        len = 1;
      }
      else if (len >= 3 && board[i][j] != board[i-1][j]) {
        for (int x = i-1; x > i-len-1; --x) {
          result[x][j] = 0;
        }
        len = 1;
      }
      else if (len < 3 && board[i][j] != board[i-1][j]) {
        len = 1;
      }
    }
  }
  // Print board
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m-1; ++j) {
      std::cout << result[i][j] << " ";
    }
    std::cout << result[i][m-1] << std::endl;
  }
}

int main(int argc, char *argv[])
{
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  matching(n, m);

  return 0;
}
