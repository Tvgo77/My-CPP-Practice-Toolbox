#include "include/leetcode.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /* Recursively solve this question */
        vector<string> output;
        //output.reserve(n*(n - 1));

        /* Recursively put parenthese in string*/
        add_parenthese(output, "", n, n);

        return output;
    }

    /* Recursive function, left is remaining '(', right is remaining ')' */
    void add_parenthese(vector<string>& output, string parenthese, int left, int right) {
        string newParenth;

        /* Return case */
        if (left == 0 && right == 0) {
            output.push_back(parenthese);
        }

        /* Append '(' if left > 0*/
        if (left > 0) {
            newParenth = parenthese + "(";
            add_parenthese(output, newParenth, left - 1, right);
        }

        /* Append ')' if right > left */
        if (right > left) {
            newParenth = parenthese + ")";
            add_parenthese(output, newParenth, left, right - 1);
        }
    }
};