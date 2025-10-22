class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left1 = 0, right1 = 0;
        int windowCount1 = 0;
        int maxFreq = 0;
        int left2 = 0;
        int windowCount2 = 0;
        int sameValueCount = 0;
        int prevValue = -1;

        for (auto num : nums) {
            if (num == prevValue)
                sameValueCount++;
            else {
                prevValue = num;
                sameValueCount = 1;
            }

            while (nums[left1] < num - k) {
                windowCount1--;
                left1++;
            }

            while (right1 < n && nums[right1] <= num + k) {
                windowCount1++;
                right1++;
            }

            maxFreq = max(maxFreq, sameValueCount + min(windowCount1 - sameValueCount, numOperations));

            windowCount2++;
            while (nums[left2] < num - 2 * k) {
                windowCount2--;
                left2++;
            }

            maxFreq = max(maxFreq, min(windowCount2, numOperations));
        }

        return maxFreq;
    }
};
