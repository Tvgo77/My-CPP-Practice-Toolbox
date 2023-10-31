#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
#include <unordered_map>

using std::string;

struct relation {
    std::string p1;
    std::string p2;
    int isCertain;

    // Define the equality operator for the struct
    bool operator==(const relation &other) const {
        return p1 == other.p1 && p2 == other.p2 && isCertain == other.isCertain;
    }
};


// Define a custom hasher
struct RelationHasher {
    size_t operator()(const relation &r) const {
        size_t h1 = std::hash<std::string>()(r.p1);
        size_t h2 = std::hash<std::string>()(r.p2);
        size_t h3 = std::hash<int>()(r.isCertain);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};


int main() {
  int n;
  scanf("%d\n", &n);

  std::unordered_set<relation, RelationHasher> uncertainList;
  std::queue<relation> certainQueue;
  for (int i = 0; i < n; i++) {
    relation r;
    std::cin >> r.p1;
    string symbol;
    std::cin >> symbol;
    if (symbol == "??") { 
      r.isCertain = 0;
      std::cin >> r.p2;
      uncertainList.insert(r);
    }
    else if (symbol == "->") {
      r.isCertain = 1;
      std::cin >> r.p2;
      certainQueue.push(r);
    }
  }

  std::unordered_set<string> notSource;
  while (certainQueue.size() > 0) {
    int originSize = certainQueue.size();
    for (int i = 0; i < originSize; i++) {
      relation r = certainQueue.front();
      notSource.insert(r.p2);
      certainQueue.pop();
    }

    std::unordered_set<relation, RelationHasher> uncertainList_copy(uncertainList);
    for (auto& r: uncertainList_copy) {
      if (notSource.count(r.p1) > 0 || notSource.count(r.p2) > 0) {
        relation newR;
        if (notSource.count(r.p1) > 0) {
          newR.p1 = r.p1;
          newR.p2 = r.p2;
          newR.isCertain = 1;
        }
        else if (notSource.count(r.p2) > 0) {
          newR.p1 = r.p2;
          newR.p2 = r.p1;
          newR.isCertain = 1;
        }
        certainQueue.push(newR);
        uncertainList.erase(r);
      }
    }
  }

  std::vector<string> possibleSource;
  for (auto& r: uncertainList) {
    possibleSource.push_back(r.p1);
    possibleSource.push_back(r.p2);
  }
  std::unordered_map<string, int> nameCount;
  for (string& s: possibleSource) {
    if (nameCount.count(s) == 0)
      nameCount[s] = 1;
    else
      nameCount[s]++;
  }

  for (auto& p: nameCount) {
    if (p.second > 1) {
      for (auto& r: uncertainList) {
        if (r.p1 == p.first) {
          notSource.insert(r.p2);
        }
        else if (r.p2 == p.first) {
          notSource.insert(r.p1);
        }
      }
    }
  }

  std::unordered_set<relation, RelationHasher> uncertainList_copy(uncertainList);
  for (auto& r: uncertainList_copy) {
    if (notSource.count(r.p1) > 0 || notSource.count(r.p2) > 0) {
      uncertainList.erase(r);
    }
  }

  std::vector<string> possibleSource2;
  for (auto& r: uncertainList) {
    possibleSource2.push_back(r.p1);
    possibleSource2.push_back(r.p2);
  }
  std::sort(possibleSource2.begin(), possibleSource2.end());

  for (string& s: possibleSource2) {
    printf("%s\n", s.c_str());
  }

  return 0;
}