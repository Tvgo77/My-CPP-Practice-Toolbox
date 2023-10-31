#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;

struct num {
  int n;
  bool isUsed;
};

void recursion(std::vector<num>& permutation, string& relation, int& output, int step, int& usingIdx) {
  if (step == permutation.size() - 1) {
    output++;
  }

  if (relation[step] == '<') {
    for (int i = usingIdx + 1; i < permutation.size(); i++) {
      if (permutation[i].isUsed == false) {
        permutation[i].isUsed = true;
        recursion(permutation, relation, output, step + 1, i);
        permutation[i].isUsed = false;
      }
    }
  }
  else {
    for (int i = usingIdx - 1; i >= 0; i--) {
      if (permutation[i].isUsed == false) {
        permutation[i].isUsed = true;
        recursion(permutation, relation, output, step + 1, i);
        permutation[i].isUsed = false;
      }
    }
  }
}

int main() {
  int n;
  string relation;
  
  scanf("%d\n", &n);
  std::cin >> relation;

  if (n == 1) {
    printf("1\n");
    return 0;
  }

  std::vector<num> permutation(n);
  for (int i = 0; i < n; i++) {
    permutation[i] = {i, false};
  }

  int output = 0;
  for (int i = 0; i < n; i++) {
    permutation[i].isUsed = true;
    recursion(permutation, relation, output, 0, i);
    permutation[i].isUsed = false;
  }

  printf("%d\n", output % (1000000007));
  return 0;
}
