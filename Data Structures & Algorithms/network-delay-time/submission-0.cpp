class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto time:times)
        {
            graph[time[0]].push_back({time[1],time[2]});
        }

        vector<int> dis(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        dis[k] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto adj:graph[u])
            {
                int v = adj.first, wt = adj.second;
                if(dis[v] > dis[u] + wt)
                {
                    dis[v] = dis[u] + wt;
                    q.push(v);
                }
            }
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            ans = max(ans,dis[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
