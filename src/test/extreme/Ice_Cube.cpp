#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

int recursion(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
              const int& maxStep, const int& minIceCube, int r, int c, int currentStep) {
  int downStep = -1;
  int rightStep = -1;
  if (grid[r][c] >= minIceCube) {
    currentStep = 0;
  }
  else {
    currentStep++;
    if (currentStep >= maxStep) {
      dp[r][c][currentStep] = -1;
      return -1;
    }
  }

  if (dp[r][c][currentStep] > -2) {
    return dp[r][c][currentStep];
  }

  if (r == grid.size() - 1 && c == grid[0].size() - 1) {
    return grid[r][c];
  }

  if (r < grid.size() - 1)
    downStep = recursion(grid, dp, maxStep, minIceCube, r + 1, c, currentStep);
  if (c < grid[0].size() - 1) {
    rightStep = recursion(grid, dp, maxStep, minIceCube, r, c + 1, currentStep);
  }

  if (downStep < 0 && rightStep < 0) {
    dp[r][c][currentStep] = -1;
    return -1;
  }
  else {
    // Current step is s when move to this cell
    dp[r][c][currentStep] = grid[r][c] + std::max(downStep, rightStep);
    return dp[r][c][currentStep];
  }
}

int main() {
  int totalCase;
  int row, col;
  int maxStep_iceless;
  int minIceCube;

  scanf("%d\n", &totalCase);

  for (int i = 0; i < totalCase; i++) {
    scanf("%d %d %d %d\n", &row, &col, &maxStep_iceless, &minIceCube);
    vector<vector<int>> grid(row, vector<int>(col));
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(maxStep_iceless + 1, -2)));
    for (int j = 0; j < row; j++) {
      for (int k = 0; k < col; k++) {
        std::cin >> grid[j][k];
      }
    }

    int output = recursion(grid, dp, maxStep_iceless, minIceCube, 0, 0, 0);
    if (output >= 0) {
      printf("Case %d: %d\n", i + 1, output);
    }
    else {
      printf("Case %d: IMPOSSIBLE\n", i + 1);
    }
  }
  
  return 0;
}