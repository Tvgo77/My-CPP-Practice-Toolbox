#include <stdio.h>
#include <vector>
#include <queue>

bool compare_cards(std::queue<int>& player1, std::queue<int>& player2) {
  // {13 10, 3}
  // {2, 11, 5, 11}
  int counter = 0;
  while (!player1.empty() && !player2.empty()) {
    if (player1.front() > player2.front()) {
      player1.push(player2.front());
      counter = 0;
    }
    else if (player1.front() < player2.front()) {
      player2.push(player1.front());
      counter = 0;
    }
    else if (player1.front() == player2.front()) {
      player1.push(player1.front());
      player2.push(player2.front());
      counter++;
    }
    player1.pop();
    player2.pop();

    if (counter > player1.size() && counter > player2.size()) {
      printf("draw\n");
      return true;
    }

    if (player1 == player2) {
      printf("draw\n");
      return true;
    } 
  }

  if (player1.empty()) {
    printf("player 2\n");
  }
  if (player2.empty()) {
    printf("player 1\n");
  }
  return true;
}

int main() {
  /* Standard input */
  int n;  // Game rounds
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    std::queue<int> player1;
    std::queue<int> player2;
    char c;
    char prev = ' ';
    while (scanf("%c", &c) == 1) {
      if (prev == ' ' && c != ' ') {
        switch (c) {
          case 'T':
            player1.push(10);
            break;
          case 'J':
            player1.push(11);
            break;
          case 'Q':
            player1.push(12);
            break;
          case 'K':
            player1.push(13);
            break;
          case 'A':
            player1.push(14);
            break;
          default:
            player1.push(c - '0');
            break;
        }
      }
      prev = c;
      if (c == '\n')
        break;
    }

    prev = ' ';
    c = ' ';
    while (scanf("%c", &c) == 1) {
      if (prev == ' ' && c != ' ') {
        switch (c) {
          case 'T':
            player2.push(10);
            break;
          case 'J':
            player2.push(11);
            break;
          case 'Q':
            player2.push(12);
            break;
          case 'K':
            player2.push(13);
            break;
          case 'A':
            player2.push(14);
            break;
          default:
            player2.push(c - '0');
            break;
        }
      }
      prev = c;
      if (c == '\n')
        break;
    }
    
    compare_cards(player1, player2);
  }

  return 0;
}