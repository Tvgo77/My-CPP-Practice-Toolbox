#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <unordered_map>

using std::vector;

struct cell {
  int rowIdx;
  int colIdx;
};

int main() {
  int row, col;
  scanf("%d %d\n", &row, &col);

  vector<vector<int>> grid(row, vector<int>(col));
  vector<vector<double>> water(row, vector<double>(col, 1.0));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      std::cin >> grid[i][j];
    }
  }

  /* Get all elevation */
  std::set<int> elevations_set;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      elevations_set.insert(grid[i][j]);
    }
  }
  std::vector<int> elevations(elevations_set.begin(), elevations_set.end());
  std::sort(elevations.begin(), elevations.end(), std::greater<int>());

  /* Add grid cell to queue from highest to lowest*/
  std::vector<std::queue<cell>> queueList(elevations.size());
  std::unordered_map<int, int> heightMap;
  for (int i = 0; i < elevations.size(); i++) {
    heightMap[elevations[i]] = i;
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int k = heightMap[grid[i][j]];
      queueList[k].push({i, j});
    }
  }
  /* Process cell in queue */
  for (auto& cellQueue: queueList) {
    int queueOriginSize = cellQueue.size();
    for (int i = 0; i < queueOriginSize; i++) {
      cell curr = cellQueue.front();
      cellQueue.pop();
      vector<cell> flowable;
      if (curr.rowIdx > 0) {
        if (grid[curr.rowIdx][curr.colIdx] > grid[curr.rowIdx - 1][curr.colIdx]) {
          flowable.push_back({curr.rowIdx - 1, curr.colIdx});
        }
      }
      if (curr.rowIdx < row - 1) {
        if (grid[curr.rowIdx][curr.colIdx] > grid[curr.rowIdx + 1][curr.colIdx]) {
          flowable.push_back({curr.rowIdx + 1, curr.colIdx});
        }
      }
      if (curr.colIdx > 0) {
        if (grid[curr.rowIdx][curr.colIdx] > grid[curr.rowIdx][curr.colIdx - 1]) {
          flowable.push_back({curr.rowIdx, curr.colIdx - 1});
        }
      }
      if (curr.colIdx < col - 1) {
        if (grid[curr.rowIdx][curr.colIdx] > grid[curr.rowIdx][curr.colIdx + 1]) {
          flowable.push_back({curr.rowIdx, curr.colIdx + 1});
        }
      }

      double split = water[curr.rowIdx][curr.colIdx] / flowable.size();
      if (!flowable.empty())
        water[curr.rowIdx][curr.colIdx] = 0;

      for (cell& c: flowable) {
        water[c.rowIdx][c.colIdx] += split;
      }
    }
  }


  /* Find the cell with most water*/
  double maxWater = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      maxWater = std::max(maxWater, water[i][j]);
    }
  }

  printf("%lf\n", maxWater);
  return 0;
}

