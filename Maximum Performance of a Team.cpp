class Solution {
public:

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int, int>>tmp;
        for(int i = 0; i < n; i++)
        {
            tmp.push_back({efficiency[i], speed[i]});
        }
        sort(tmp.rbegin(), tmp.rend());
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        long long spe = 0;
        for(int i = 0; i < n; i++)
        {
            spe += tmp[i].second;
            int effi = tmp[i].first;
            // cout << spe << " " << effi << endl;
            if(pq.size() == k)
            {
                spe -= pq.top();
                pq.pop();
            }
            // cout << spe << " " << effi << endl;
            pq.push(tmp[i].second);
            ans = max(ans, spe * effi);
        }
        return ans % (long long int)(1e9 + 7);
    }
};

// tc o(nlogn)
// sc o(n)
