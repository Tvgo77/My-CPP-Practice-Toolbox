#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <array>

using namespace std;

// int function(int64_t& InputA, int64_t& InputB, int64_t& InputC) {
//     int64_t v0 = InputA;
//     int64_t v1 = InputB;
//     int64_t v2 = InputC;
//     int64_t v3 = 1;
//     int64_t v4 = 0;
//     int64_t v5 = -1;
//     int64_t v6 = 1;
//     int64_t v7 = 0;
//     int64_t v8 = InputA;
//     int64_t v9 = InputA + InputB;
//     int64_t v10 = 0;
//     int64_t v11 = 0;
//     int64_t v12 = 1;
//     for (; v12 <= v2; ++v12) {
//         v11 += v1;
//         v10 += v0;
//         int64_t v13 = v10;
//         int64_t v14 = 0;
//         int64_t v15 = 0;
//         while (true) {
//             int64_t v16 = v13 + v13;
//             if (v16 <= v1) {
//                 v13 -= v1;
//                 ++v14;
//                 v15 += v1;
//             } else {
//                 break;
//             }
//         }
//         if (v13 <= v4) {
//             v13 = v4 - v13;
//         }
//         int64_t v17 = v4;
//         int64_t v18 = v3;
//         do {
//             v17 += v13;
//             ++v18;
//         } while (v18 <= v6);
//         v18 = v3;
//         do {
//             v17 -= v9;
//             ++v18;
//         } while (v18 <= v12);
//         if (v17 >= v4) {
//             v5 = v14;
//             v6 = v12;
//             v7 = v15;
//             v8 = v10;
//             v9 = v13;
//         }
//     }
//     return v6;
// }

int64_t function(int64_t InputA, int64_t InputB, int64_t InputC) {
    int64_t v0 = InputA;
    int64_t v1 = InputB;
    int64_t v2 = InputC;

    int64_t v3 = 1;
    int64_t v4 = 0;
    int64_t v5 = -1;
    int64_t v6 = 1;
    int64_t v7 = -v1;
    int64_t v8 = v0;
    int64_t v9 = v0 + v1;
    int64_t v10 = 0;
    int64_t v11 = 0;
    int64_t v12 = 1;

    while (true) {
        v11 += v1;
        v10 += v0;
        int64_t v13 = v10;
        int64_t v14 = 0;
        int64_t v15 = 0;

        while (true) {
            int64_t v16 = v13 + v13;
            if (v16 <= v1) {
                break;
            }
            v13 -= v1;
            v14 += 1;
            v15 += v1;
        }

        if (v13 <= 0) {
            v13 = -v13;
        }

        int64_t v17 = 0;
        int64_t v18 = 1;

        while (v18 <= v6) {
            v17 += v13;
            v18 += 1;
        }

        v18 = 1;

        while (v18 <= v12) {
            v17 -= v9;
            v18 += 1;
        }

        if (v17 < 0) {
            v5 = v14;
            v6 = v12;
            v7 = v15;
            v8 = v10;
            v9 = v13;
        }

        v12 += 1;
        if (v12 > v2) {
            break;
        }
    }

    return v6;
}




int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::array<int64_t, 3>> inputList(n);

  for (int i = 0; i < n; i++) {
    scanf("%ld %ld %ld", &inputList[i][0], &inputList[i][1], &inputList[i][2]);
  }

  for (int i = 0; i < n; i++) {
    int64_t output = function(inputList[i][0], inputList[i][1], inputList[i][2]);
    printf("%ld\n", output);
  }
  
  return 0;
}

