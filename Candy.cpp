class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();
        vector<int>ans(n, 1);
        if(n == 1)
        {
            return 1;
        }
        // LEFT
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        // RIGHT
        for(int i = n - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                ans[i] = max(ans[i], ans[i + 1] + 1);
            }
        }
        int sum = 0;
        for(auto x : ans)
        {
            sum += x;
        }
        return sum;
    }
};

 

// tc o(n)
// sc o(n)
