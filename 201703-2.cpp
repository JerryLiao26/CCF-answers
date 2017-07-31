#include <iostream>

void queue(int *line, int len, int no, int shift) {
  int index = -1;
  // Search for student
  for (int i = 0; i < len; ++i) {
    if (line[i] == no) {
      index = i;
      break;
    }    
  }

  int temp = line[index];
  int target = shift + index;

  // Shift backward
  if (shift >= 0) {
    for (int i = index; i < target; ++i) {
      line[i] = line[i + 1];
    }
  }
  // Shift forward
  else {
    for (int i = index; i > target; --i) {
      line[i] = line[i - 1];
    }
  }
  line[target] = temp;
}

void print_line(int *line, int len) {
  for (int i = 0; i < len - 1; ++i) {
    std::cout << line[i] << " ";    
  }
  std::cout << line[len - 1] << std::endl;
}

int* make_line(int num) {
  int *temp = new int[num];
  for (int i = 0; i < num; ++i) {
    temp[i] = i + 1;
  }
  return temp;
}

int main(int argc, char *argv[])
{
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  int *line;
  line = make_line(n);

  for (int i = 0; i < m; ++i) {
    int x = 0;
    int y = 0;
    std::cin >> x >> y;
    queue(line, n, x, y);
  }

  print_line(line, n);

  return 0;
}
