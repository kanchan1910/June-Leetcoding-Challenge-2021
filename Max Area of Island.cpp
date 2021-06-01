class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<bool>>& vis, int& count)
    {
        if(i >= n || i < 0 || j  < 0 || j >= m || vis[i][j] == true || grid[i][j] == 0)
        {
            return;
        }
        count++;
        vis[i][j] = true;
        dfs(i + 1, j, grid, n, m, vis, count);
        dfs(i - 1, j, grid, n, m, vis, count);
        dfs(i, j + 1, grid, n, m, vis, count);
        dfs(i, j - 1, grid, n, m, vis, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    int count = 0;
                    dfs(i, j, grid, n, m, vis, count);
                    area = max(area, count);
                }
            }
        }
        return area;
    }
};
