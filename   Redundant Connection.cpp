class Solution {
public:
    bool dfs(int start, int end, vector<bool>& vis, map<int, vector<int>>& m)
    {
        vis[start] = true;
        if(start == end)
        {
            return true;
        }
        for(auto child : m[start])
        {
            if(!vis[child])
            {
                if(dfs(child, end, vis, m) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        map<int, vector<int>>m;
        int n = edges.size();
        vector<bool>vis(n + 1, false);
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            fill(vis.begin(), vis.end(), false);
            
            if(m.find(u) != m.end() && m.find(v) != m.end() && dfs(u, v, vis, m) == true)
            {
                return {u, v};
            }
            m[u].push_back(v);
            m[v].push_back(u);
        }
        return {};
    }
};

// main logic is if we have not added the edge between two nodes, then if we can reach from u to v, then the current edge is of no use and hence redundant
