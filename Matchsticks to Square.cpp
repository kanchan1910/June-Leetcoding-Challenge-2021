class Solution {
public:
    bool fun(vector<int>& matchsticks, vector<bool>& vis, int index, int sides, int target, int cur_sum)
    {
        // if we've filled all the subsets then definitely a valid partition exists so return true
        if(sides == 0)
        {
            return true;
        }
        // if we've filled one subset completely, we'll focus on filling the next subset starting from the 0th index
        if(cur_sum == target)
        {
            return fun(matchsticks, vis, 0, sides - 1, target, 0);
        }
        // Now we'll try to fill our current subset
        for(int i = index; i < matchsticks.size(); i++)
        {
        
            // if an element is unvisited and can be added to the current subset sum (i.e. adding that element to our current subset wont exceed it's sum from the desired value , then add it)
            if(!vis[i] && cur_sum + matchsticks[i] <= target)
            {
                vis[i] = true;
                bool tmp = fun(matchsticks, vis, i + 1, sides, target, cur_sum + matchsticks[i]);
                if(tmp == true)
                {
                    return true;
                }
                vis[i] = false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks)
    {
        // calculate sum of all matchsticks
        int sum = 0;
        int n = matchsticks.size();
        if(n < 4)
        {
            return false;
        }
        for(int i = 0; i < n; i++)
        {
            sum += matchsticks[i];
        }
        // if sum is not divisable by k then it can not be partitioned 
        if(sum % 4 != 0)
        {
            return false;
        }
        vector<bool>vis(n, false);
        return fun(matchsticks, vis, 0, 4, sum / 4, 0);
    }
};
