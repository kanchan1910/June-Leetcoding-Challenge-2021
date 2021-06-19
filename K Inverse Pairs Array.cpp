class Solution {
public:
    // int dp[1005][1005];
//     int fun(int n, int k)
//     {
//         // base case
//         if(n == 0)
//         {
//             return 0;
//         }
//         if(k == 0)
//         {
//             // only sorted array will be the desired permutation
//             return 1;
//         }
//         if(dp[n][k] != -1)
//         {
//             return dp[n][k];
//         }
//         int ans = 0;
//         for(int i = 0; i <= min(k, n - 1); i++)
//         {
//             ans = (ans + fun(n - 1, k - i)) % 1000000007;
//         }
//         return dp[n][k] = ans;

//     }
    int kInversePairs(int n, int k)
    {
    //     memset(dp, -1, sizeof(dp));
    //     return fun(n, k);
        int dp[n + 1][k + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++) 
            {
                if (j == 0)
                {
                   dp[i][j] = 1;   
                }
                else if(i == 0)
                {
                    dp[i][j] = 0;
                }
                else 
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
                    if(j - i >= 0)
                    {
                        dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + 1000000007) % 1000000007;
                    }
                }
            }
        }
        return dp[n][k];
    }
};

// tc O(nk)
// sc o(nk)

// tle wale ka 
// tc o(nnk)
// sc o(nk)
