class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int n = nums.size();
        int count = 0;
        int ans = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                ans = max(ans, i - start + 1); 
            }
            else
            {
                count++;
                if(count <= k)
                {
                    ans = max(ans, i - start + 1);
                }
                else
                {
                    while(count > k)
                    {
                        if(nums[start] == 1)
                        {
                            start++;
                        }
                        else
                        {
                            count--;
                            start++;
                        }
                    }
                    ans = max(ans, i - start + 1);
                }
            }
        }
        return ans;
    }
};

// tc o(n)
// sc o(1)
