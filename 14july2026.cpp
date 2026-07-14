class Solution {
public:
    static const int MOD = 1000000007;

    int n;
    vector<int> nums;

    // memo[idx][g1][g2]
    int memo[201][201][201];

    int solve(int idx, int g1, int g2) {
        if (idx == n) {
            return (g1 != 0 && g1 == g2);
        }

        int &ans = memo[idx][g1][g2];
        if (ans != -1) return ans;

        long long res = 0;

        // Option 1: Ignore current element
        res += solve(idx + 1, g1, g2);

        // Option 2: Put in seq1
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        res += solve(idx + 1, ng1, g2);

        // Option 3: Put in seq2
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        res += solve(idx + 1, g1, ng2);

        ans = res % MOD;
        return ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0);
    }
};
