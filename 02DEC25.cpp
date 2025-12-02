#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;
        unordered_map<int,long long> cnt;
        for(auto &p : points) cnt[p[1]]++;

        vector<long long> ways;
        for(auto &it : cnt) {
            long long c = it.second;
            if(c >= 2) ways.push_back(c * (c - 1) / 2 % MOD);
        }

        long long ans = 0, pref = 0;
        for(long long v : ways) {
            ans = (ans + v * pref) % MOD;
            pref = (pref + v) % MOD;
        }
        return ans % MOD;
    }
};
