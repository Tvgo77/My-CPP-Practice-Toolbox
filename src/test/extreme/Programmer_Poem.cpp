// 2 6
// hash dash crash slash
// underscore four

// Waka waka bang splat tick tick hash
// Caret quote back tick dollar dollar dash
// Bang splat equal at dollar underscore
// Percent splat waka waka tilde number four
// Ampersand bracket bracket dot dot slash
// Vertical bar curly bracket comma comma CRASH

#include <stdio.h>
#include <unordered_set>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using std::unordered_set;
using std::vector;

struct rhyme {
  unordered_set<std::string> group;
  char c;
};

int main() {
  int rhymeNum, lineNum;
  scanf("%d %d\n", &rhymeNum, &lineNum);

  vector<rhyme> rhymeList(rhymeNum, {unordered_set<std::string> () , ' '});

  for (int i = 0; i < rhymeNum; i++) {
    std::string line;
    std::getline(std::cin, line); // Read a line of input

    std::istringstream iss(line);
    std::string word;

    while (iss >> word) { // Extract strings from the line
      rhymeList[i].group.insert(word);
    }
  }

  std::string line;
  std::getline(std::cin, line);
  std::vector<std::string> finalWords(lineNum);
  for (int i = 0; i < lineNum; i++) {
    std::string line;
    std::getline(std::cin, line); // Read a line of input

    std::istringstream iss(line);
    std::string word;
    std::string finalWord;

    while (iss >> word) { // Extract strings from the line
      finalWord = word;
    }
    finalWords[i] = finalWord;
    std::transform(finalWords[i].begin(), finalWords[i].end(), finalWords[i].begin(), ::tolower);
  }

  /* For every Final word */
  std::string output(lineNum, 32);
  int used_rhymeCount = 0;
  for (int i = 0; i < lineNum - 1; i++) {
    /* Search word in rhymeList */
    char name = 'X';
    for (rhyme& r: rhymeList) {
      if (r.group.count(finalWords[i]) > 0) {
        /* Check if next word is in the same list*/
        if (r.group.count(finalWords[i + 1]) > 0) {
          if (r.c == ' ') {  // If this rhyme not used
            r.c = char('A' + used_rhymeCount);
            used_rhymeCount++;
          }
          /* give name for this and next  */
          if (output[i] == ' ')
            output[i] = r.c;
          output[i + 1] = r.c;
          break;
        }
        else {
          break;
        } 
      }
      else {
        continue;
      }
    }
    if (output[i] == ' ')
      output[i] = name;
  }
  if (output[output.size() - 1] == ' ')
    output[output.size() - 1] = 'X';

  printf("%s\n", output.c_str());
  return 0;
}