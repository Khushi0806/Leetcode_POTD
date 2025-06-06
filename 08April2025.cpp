class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_suffix(n);
        
        // Precompute min suffix
        min_suffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(s[i], min_suffix[i + 1]);
        }
        
        stack<char> t;
        string result;
        int i = 0;
        
        while (i < n || !t.empty()) {
            // If stack is not empty and top of t <= min remaining char in s, pop from t
            if (!t.empty() && (i == n || t.top() <= min_suffix[i])) {
                result += t.top();
                t.pop();
            } else {
                // Push next character from s into t
                t.push(s[i]);
                i++;
            }
        }
        
        return result;
    }
};
