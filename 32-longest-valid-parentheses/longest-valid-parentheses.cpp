
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        stack.push_back(-1);

        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();

                if (stack.empty()) {
                    stack.push_back(i);
                } else {
                    maxLength = max(maxLength, i - stack.back());
                }
            }
        }

        return maxLength;
    }
};
