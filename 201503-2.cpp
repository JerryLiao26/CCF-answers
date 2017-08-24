#include <iostream>
#include <algorithm>

struct freqNode {
  int value;
  int freq;
};

bool compNode(freqNode a, freqNode b) {
  if (a.freq == b.freq) {
    return a.value < b.value;
  }
  else {
    return a.freq > b.freq;
  }
}

void print_freq(freqNode *group, int len) {
  std::sort(group, group + len, compNode);
  for (int i = 0; i < len; ++i) {
    std::cout << group[i].value << " " << group[i].freq << std::endl;
  }
}

int search_freq(int target, freqNode *group, int len) {
  for (int i = 0; i < len; ++i) {
    if (group[i].value == target) {
      return i;
    }
  }
  return -1;
}

void calc_freq(int *arr, int num) {
  int len = 0;
  freqNode *group = new freqNode[num];
  for (int i = 0; i < num; ++i) {
    int index = search_freq(arr[i], group, len);
    if (index == -1) {
      group[len].value = arr[i];
      group[len].freq = 1;
      len ++;
    }
    else {
      group[index].freq += 1;
    }
  }
  print_freq(group, len);
}

int main(int argc, char *argv[])
{
  int num = 0;
  std::cin >> num;

  int *arr = new int[num];
  for (int i = 0; i < num; ++i) {
    std::cin >> arr[i];
  }

  calc_freq(arr, num);

  return 0;
}
