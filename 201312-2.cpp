#include <iostream>
#include <string>

int char2int(char c) {
  return (int)c - 48;
}

char int2char(int i) {
  return (char)(i + 48);
}

std::string check_ISBN(std::string code) {
  std::string result = "";
  int sum = 0;
  int count = 1;
  int last = code.length() - 1;
  for (int i = 0; i < 11; ++i) {
    if (i != 1 && i != 5) { // Skip dash
      sum += char2int(code[i]) * count;
      count++;
    }
  }
  int temp = sum % 11;
  if (temp == 10) {
    if (code[last] == 'X') {
      return "Right";
    }
    else {
      code[last] = 'X';
    }
  }
  else {
    if (code[last] == int2char(temp)) {
      return "Right";
    }
    else {
      code[last] = int2char(temp);
    }
  }
  result = code;
  return result;
}

int main(int argc, char *argv[])
{
  std::string code = "";
  std::cin >> code;
  
  std::cout << check_ISBN(code) << std::endl;

  return 0;
}
