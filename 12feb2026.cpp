class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            if (n - l <= ans) break;

            int cnt[26] = {0};
            int uniq = 0, mx = 0;

            for (int r = l; r < n; r++) {
                int idx = s[r] - 'a';

                if (cnt[idx] == 0) uniq++;

                cnt[idx]++;
                mx = max(mx, cnt[idx]);

                int len = r - l + 1;

                if (len == uniq * mx)
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};
