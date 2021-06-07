class Solution {
public:
    // memoization
    int fun(int index, int n, vector<int>&cost, vector<int>& dp)
    {
        // base case
        if(index >= n)
        {
            return 0;
        }
        // checking in cache
        if(dp[index] != -1)
        {
            return dp[index];
        }
        // performing recursion step and storing the result in dp[] for future use
        return dp[index] = cost[index] + min(fun(index + 1, n, cost, dp), fun(index + 2, n, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int>dp(n, -1);
        // answer will be the minimum of both
        return min(fun(0, n, cost, dp), fun(1, n, cost, dp));
    }
};
// tc o(n)
// sc o(n)
