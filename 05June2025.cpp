class Solution {
public:
    // Find with path compression
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    // Union: attach the larger root to the smaller root (lexicographically smaller)
    void unite(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX == rootY) return;
        if (rootX < rootY) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        // Initialize each letter to be its own parent
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        // Union each pair of equivalent characters
        for (int i = 0; i < s1.length(); ++i) {
            unite(parent, s1[i] - 'a', s2[i] - 'a');
        }

        // Build the result by finding the smallest equivalent character for each in baseStr
        string result;
        for (char ch : baseStr) {
            int root = find(parent, ch - 'a');
            result += (char)(root + 'a');
        }

        return result;
    }
};
