#include <iostream>
#include <string>

std::string convert(std::string input)
{
  return "";
}

int main(int argc, char *argv[])
{
  std::std::string line;
  while (std::getline(std::cin, line)) {
    std::string input = "";
    std::cin >> input;

    std::cout << convert(input) << std::endl;
  }
  return 0;
}
