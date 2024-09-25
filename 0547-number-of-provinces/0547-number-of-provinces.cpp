#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int> adj[], vector<int> &visited, int Node) {
        visited[Node] = 1;
        for (auto it : adj[Node]) {
            if (!visited[it])
                dfs(adj, visited, it);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        vector<int> adj[V]; 
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }

        return count;
    }
};
