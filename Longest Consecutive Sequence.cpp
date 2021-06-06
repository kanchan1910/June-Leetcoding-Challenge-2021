class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int len = 1;
        int max_len = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i + 1] - nums[i] == 1)
            {
                len++;
            }
            else if(nums[i + 1] - nums[i] == 0)
            {
                continue;
            }
            else
            {
                max_len = max(max_len, len);
                len = 1;
            }
                
        }
        max_len = max(max_len, len);
        return max_len;
    }
};



// tc o(nlogn)
// sc o(1)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        int max_len = 0;
        unordered_set<int>s;
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(s.find(nums[i] - 1) == s.end())
            {
                int j =  nums[i];
                while(s.find(j) != s.end())
                {
                    j++;
                }
                max_len = max(max_len, j - nums[i]);
            }
        }
        return max_len;
    }
};


// tc o(n)
// sc o(n)
