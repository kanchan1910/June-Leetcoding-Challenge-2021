class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            int best = INT_MIN;
            for (int j = max(0, i - k); j < i; j++)
            {
                best = max(best, nums[j] + nums[i]);
            }
            nums[i] = best;
        }
        return nums[n-1];
    }
};


// TLE
// tc o(n * k)
// sc o(1)


// We need a way to get a maximum value from [dp[i-k], dp[i-k+1], ..., dp[i-1]] in O(1).


class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<int>q;
        q.push_front(0);
        for(int i = 1; i < n; i++)
        {
             nums[i] = nums[i] + nums[q.front()];
             while(!q.empty() && nums[q.back()] <= nums[i])
             {
                q.pop_back();   
             }
             q.push_back(i);
             while(!q.empty() && (i-q.front()) >= k)
             {
                q.pop_front();   
             }
        }
        return nums[n - 1];
    }
};



// ACCEPTED
// tc o(n)
// sc o(n)
