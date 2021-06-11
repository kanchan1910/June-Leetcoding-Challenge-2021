class Solution {
public:
    int dp[1001][1001];
    
    int solve(vector<int> &stones, int left, int right, int sum)
    {
        if(left>=right)
            return 0;
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        if(left-right==1)
            return dp[left][right]=max(stones[left],stones[right]);
        
        int first=sum-stones[left]-solve(stones, left+1, right, sum-stones[left]);
        int second=sum-stones[right]-solve(stones, left, right-1, sum-stones[right]);
        
        return dp[left][right]=max(first,second);
        
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int i,sum=0;
        for(i=0;i<n;i++)
        {
            sum+=stones[i];
        }
        
        memset(dp, -1, sizeof(dp));
        return solve(stones,0,n-1,sum);
        
        
        
    }
};
