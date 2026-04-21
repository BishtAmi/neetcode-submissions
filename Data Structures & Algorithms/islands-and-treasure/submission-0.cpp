class Solution {
public:
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    void findNearestIslands(int i,int j,int score,vector<vector<int>>& grid)
    {
        if(i>=n || j>=m) return;
        grid[i][j] = min(grid[i][j],score);
        for(int r=0; r<4; r++)
        {
            int x = i + dx[r];
            int y = j + dy[r];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y] > score)
            {
                findNearestIslands(x,y,score+1,grid);
            }
        }       
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0)
                {
                    findNearestIslands(i,j,0,grid);
                }
            }
        }
    }
};
