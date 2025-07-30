class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int longest = 0, current = 0;
        
        for (int num : nums) {
            if (num == max_val) {
                current++;
                longest = max(longest, current);
            } else {
                current = 0;
            }
        }
        
        return longest;
    }
};
