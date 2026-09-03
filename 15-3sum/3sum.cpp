#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        
        // Sort the array to use two pointers and easily skip duplicates
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum < 0) {
                    l++; // Need a larger sum, move left pointer right
                } else if (sum > 0) {
                    r--; // Need a smaller sum, move right pointer left
                } else {
                    // Found a triplet
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    // Skip duplicate elements for the second number
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                }
            }
        }
        
        return res;
    }
};