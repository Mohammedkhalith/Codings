class Solution {
public:
    vector<string> result;

    void backtrack(string& digits, int index, string& current,
                   vector<string>& keypad) {

        // All digits are processed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = keypad[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);              // choose
            backtrack(digits, index + 1, current, keypad);
            current.pop_back();                 // remove / backtrack
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> keypad = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string current = "";

        backtrack(digits, 0, current, keypad);

        return result;
    }
};