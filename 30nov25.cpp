class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int rem = total % p;
        if (rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long curr = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            int target = (curr - rem + p) % p;
            if (mp.count(target)) ans = min(ans, i - mp[target]);
            mp[curr] = i;
        }

        return ans == n ? -1 : ans;
    }
};
