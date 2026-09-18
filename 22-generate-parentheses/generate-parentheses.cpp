class Solution {
public:
    vector<string> result;

    void generate(string current, int open, int close, int n) {
        // Complete combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have opening brackets
        if (open < n) {
            generate(current + "(", open + 1, close, n);
        }

        // Add ')' only if it won't make the expression invalid
        if (close < open) {
            generate(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return result;
    }
};