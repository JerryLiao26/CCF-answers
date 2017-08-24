#include <iostream>

void print_board(int board[15][10]) {
  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 9; ++j) {
      std::cout << board[i][j] << " ";
    }
    std::cout << board[i][9] << std::endl;
  }
}

int empty_lines(int block[4][4]) {
  int empty = 0;
  for (int i = 3; i >= 0; --i) {
    for (int j = 0; j < 4; ++j) {
      if (block[i][j] == 1) {
        return empty;
      }
    }
    empty++;
  }
  return empty;
}

void copy_board(int source[15][10], int dest[15][10]) {
  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 10; ++j) {
      dest[i][j] = source[i][j];
    }
  }
}

void gen_board(int board[15][10], int block[4][4], int pos) {
  pos -= 1; // Convert index
  int empty = empty_lines(block); // Get empty lines
  int bottom = 0; // Align bottom of the block to the line of the board
  bool finish = false; // Finish flag
  int result[15][10]; // Store result board
  copy_board(board, result); // Init result board, important
  while(true) {
    int temp[15][10];
    copy_board(board, temp);
    for (int i = bottom; i > bottom-4+empty && i >= 0; --i) {
      for (int j = pos; j < pos+4; ++j) {
        temp[i][j] += block[i-bottom+3-empty][j-pos];
        if (temp[i][j] > 1) {
          i = -1; // To stop outer for loop
          finish = true; // Set flag
          break;
        }
      }
    }
    if(!finish) {
      bottom++;
      copy_board(temp, result);
    }
    else {
      copy_board(result, board);
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  int board[15][10];
  int block[4][4];
  int pos = 0;

  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cin >> board[i][j];
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cin >> block[i][j];
    }
  }
  std::cin >> pos;

  gen_board(board, block, pos);
  print_board(board);

  return 0;
}
