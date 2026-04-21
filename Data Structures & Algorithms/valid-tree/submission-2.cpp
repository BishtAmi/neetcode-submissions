class Solution {
public:
   int cnt = 0;
    bool isCycle(int u,int par,vector<int> &vis,vector<vector<int>> &graph)
    {
        vis[u] = 1;
        cnt++;
        for(auto v:graph[u])
        {
            if(vis[v] == 0)
            {
                if(isCycle(v,u,vis,graph)) return true;
            }
            else if(v != par)
            {
                return true;
            } 
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> vis(n,0);
        for(auto edge:edges)
        {
            auto u = edge[0] , v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cnt = 0;
        return !isCycle(0,-1,vis,graph) && cnt == n;
    }
};
