#include <algorithm>
#include <iostream>
#include <vector>

struct mouse {
  int x;
  int y;
};

struct window {
  int no;
  int x1;
  int y1;
  int x2;
  int y2;
};

bool within(mouse click, window one) {
  if (click.x >= one.x1 && click.x <= one.x2) {
    if (click.y >= one.y1 && click.y <= one.y2) {
      return true;
    }
  }
  return false;
}

void check(mouse click, std::vector<window> &group) {
  int len = group.size();
  for (int i = len-1; i >= 0; i--) {
    if (within(click, group[i])) {
      std::cout << group[i].no << '\n';
      // Move window to top
      for (int j = i; j < len-1; j++) {
        std::swap(group[j], group[j+1]);
      }
      return;
    }
  }
  std::cout << "IGNORED" << '\n';
}

int main(int argc, char const *argv[]) {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;

  std::vector<window> group;
  for (int i = 0; i < n; i++) {
    window cur;
    cur.no = i+1;
    std::cin >> cur.x1 >> cur.y1 >> cur.x2 >> cur.y2;
    group.push_back(cur);
  }

  for (int i = 0; i < m; i++) {
    mouse click;
    std::cin >> click.x >> click.y;
    check(click, group);
  }

  return 0;
}
