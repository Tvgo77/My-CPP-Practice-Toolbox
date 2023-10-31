#include <stdio.h>
#include <iostream>
#include <vector>

int main() {
  int n;
  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    std::string input;
    std::vector<int> charCount(7, 0);
    std::getline(std::cin, input); 
    
    for (char c: input) {
      if (0 <= c - 'a' && c - 'a' <= 6) {
        charCount[c - 'a']++;
      }
    }

    int maxOccur = 0;
    int maxIdx = 0;
    for (int i = 0; i < 7; i++) {
      if (charCount[i] >= maxOccur) {
        maxOccur = charCount[i];
        maxIdx = i;
      }
    }

    printf("%c\n", std::toupper(char(maxIdx + 'a')));
  }

  
  return 0;
}