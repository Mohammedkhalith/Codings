#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman_values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // If the current numeral is smaller than the next one, subtract it
            if (i < s.length() - 1 && roman_values[s[i]] < roman_values[s[i+1]]) {
                total -= roman_values[s[i]];
            } 
            // Otherwise, add it
            else {
                total += roman_values[s[i]];
            }
        }
        
        return total;
    }
};