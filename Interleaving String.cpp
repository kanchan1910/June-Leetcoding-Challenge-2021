class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        string total = s1 + s2;
        if(total.length() != s3.length())
        {
            return false;
        }
        unordered_map<char, int>m1, m2;
        for(int i = 0; i < total.length(); i++)
        {
            m1[total[i]]++;
        }
        for(int i = 0; i < s3.length(); i++)
        {
            m2[s3[i]]++;
        }
        if(m1 != m2)
        {
            return false;
        }
        int n = s1.length();
        int m = s2.length();
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                else if(i == 0)
                {
                    if(s2[j - 1] == s3[j - 1])
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else if(j == 0)
                {
                    if(s1[i - 1] == s3[i - 1])
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else if(s1[i - 1] != s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
                {
                    dp[i][j] = false;
                }
                
                else if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                
                else if(s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                
                else if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};

// tc o(n * m)
// sc o(n * m)

// without dp 
// tc o(2 ^ (m + n))
// sc o(1)
