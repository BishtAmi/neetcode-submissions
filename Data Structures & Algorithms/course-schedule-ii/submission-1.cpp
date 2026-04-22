class Solution {
   public:
    vector<int> ans;
    bool dfs(int u,vector<vector<int>> &graph,vector<int> &dfsVis,vector<int> &vis)
    {
        vis[u] = 1;
        dfsVis[u] = 1;
        for(auto v:graph[u])
        {
            if(vis[v] == 0)
            {
                if(!dfs(v,graph,dfsVis,vis)) return false;
            }
            else if(dfsVis[v])
            {
                return false;
            }
        }
        dfsVis[u] = 0;
        ans.push_back(u);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0),dfsVis(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
        }
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if(!dfs(i,graph,dfsVis,vis))
                   return {};
            }
        }

        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
