class Solution {
public:
    vector<int> dp;
    int n;

    int solve(int idx, vector<int>& arr, int d) {
        if (dp[idx] != -1)
            return dp[idx];

        int ans = 1; // count current index

        // Move right
        for (int j = idx + 1; j <= min(n - 1, idx + d); j++) {
            if (arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + solve(j, arr, d));
        }

        // Move left
        for (int j = idx - 1; j >= max(0, idx - d); j--) {
            if (arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + solve(j, arr, d));
        }

        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.assign(n, -1);

        int res = 1;

        for (int i = 0; i < n; i++) {
            res = max(res, solve(i, arr, d));
        }

        return res;
    }
};
