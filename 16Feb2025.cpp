class Solution {
    public:
      vector<int> constructDistancedSequence(int n) {
        const int len = 2 * n - 1;
        vector<int> ans(len);    
        function<bool(int, int)> dfs = [&](int i, int s) {      
          if (i == len) return true;
          if (ans[i]) return dfs(i + 1, s);
          for (int d = n; d > 0; --d) {
            const int j = i + (d == 1 ? 0 : d);
            if ((s & (1 << d)) || j >= len || ans[j]) continue;
            ans[i] = ans[j] = d;
            if (dfs(i + 1, s | (1 << d))) return true;
            ans[i] = ans[j] = 0;
          }
          return false;
        };
        dfs(0, 0);
        return ans;
      }
    };