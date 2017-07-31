#include <iostream>
#include <queue>

int divide_cake(std::queue<int> &cake, int min) {
  int mem = 0;
  int count = 0;
  while (!cake.empty()) {
    mem += cake.front();
    cake.pop();
    if (mem >= min) {
      mem = 0;
      count += 1;
    }
  }
  
  if (cake.empty() && mem != 0) {
    count ++;
  }

  return count;
}

int main(int argc, char *argv[]) {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;

  std::queue<int> cake;
  for (int i = 0; i < n; ++i) {
    int weight;
    std::cin >> weight;
    cake.push(weight);
  }

  std::cout << divide_cake(cake, k) << std::endl;

  return 0;
}
