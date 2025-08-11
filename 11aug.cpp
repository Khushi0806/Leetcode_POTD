#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        
        // Extract powers of 2 from n
        for (int bit = 0; bit < 31; ++bit) {
            if (n & (1 << bit)) {
                powers.push_back(1 << bit);
            }
        }
        
        // Sort in non-decreasing order (though naturally in increasing order from bit extraction)
        sort(powers.begin(), powers.end());
        
        // Prefix products modulo MOD
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < (int)powers.size(); i++) {
            prefix[i+1] = (prefix[i] * powers[i]) % MOD;
        }
        
        // Answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long res = (prefix[r+1] * modInverse(prefix[l], MOD)) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
    
    // Modular exponentiation
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    // Modular inverse using Fermat's Little Theorem (since MOD is prime)
    long long modInverse(long long a, long long mod) {
        return modPow(a, mod - 2, mod);
    }
};
