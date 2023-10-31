#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <sstream>

using std::vector;
using std::string;
using std::unordered_set;

bool compare_pwd(string& pwd1, string& pwd2, vector<vector<string>>& dictList) {
  for (vector<string>& dict: dictList) {
    for (const string& s1: dict) {
      int pos1 = pwd1.find(s1);
      if (pos1 < 0) {
        continue;
      }
      while (pos1 >= 0) {
        /* Compare prefix part of pwd1 and pwd2 */
        int result = pwd1.compare(0, pos1 - 0, pwd2, 0, pos1 - 0);
        if (result == 0) {  // prefix is the same
          /* Search if other word in this dict are following prefix */
          int pos2;
          for (const string& s2: dict) {
            if (s2 == s1) continue;  // Don't search same word
            pos2 = pwd2.find(s2, pos1);
            if (pos2 == pos1) {  // Find word in dict;
              /* Compare suffix */
              int suffixCMP = pwd1.compare(pos1 + s1.size(), pwd1.size() - pos1 - s1.size(),
                                     pwd2, pos2 + s2.size(), pwd2.size() - pos2 - s2.size());
              if (suffixCMP == 0) {  // Suffix is the Same
                return false;  // Not secure
              }
              else {  // Suffix Not the same
                break; 
              }
            }
          }
          // if (pos2 != pos1) {  // Didn't find word in dict
          //   //continue;
          //   break;
          // }
        }
        else {  // prefix not match. Check if there are other word in dict.
          break;
        }

        pos1 = pwd1.find(s1, pos1 + 1);
      }
    }
  }

  return true;
}

int main() {
  /* Standard Input */
  int n;  // Dictionary num
  scanf("%d", &n);

  vector<vector<string>> dictList(n);

  for (int i = 0; i < n; i++) {
    int wordNum;
    std::cin >> wordNum;

    for (int j = 0; j < wordNum; j++) {
      std::string word;
      std::cin >> word;
      dictList[i].push_back(word);
    }
  }

  int pairNum;
  scanf("%d", &pairNum);
  for (int i = 0; i < pairNum; i++) {
    std::string password1;
    std::string password2;
    std::cin >> password1;
    std::cin >> password2;
    bool isOK = compare_pwd(password1, password2, dictList);
    if (isOK) printf("OK\n");
    else printf("REJECT\n");
  }

  return 0;
}

//Pass123 pass124