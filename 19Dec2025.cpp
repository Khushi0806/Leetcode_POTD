#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<int> knows(n, 0);
        knows[0] = 1;
        knows[firstPerson] = 1;

        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        int token = 1;

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            vector<int> touched;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == t) {
                int u = meetings[j][0];
                int v = meetings[j][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                touched.push_back(u);
                touched.push_back(v);
                j++;
            }

            queue<int> q;
            for (int x : touched) {
                if (knows[x] && visited[x] != token) {
                    visited[x] = token;
                    q.push(x);
                }
            }

            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nxt : adj[cur]) {
                    if (visited[nxt] != token) {
                        visited[nxt] = token;
                        q.push(nxt);
                    }
                }
            }

            for (int x : touched) {
                if (visited[x] == token) knows[x] = 1;
                adj[x].clear();   // reset only used nodes
            }

            token++;
            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (knows[i]) ans.push_back(i);
        return ans;
    }
};
