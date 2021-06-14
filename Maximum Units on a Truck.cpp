class Solution {
public:
    static bool com(vector<int>& a, vector<int>& b)
    {
        if(a[1] == b[1])
        {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), com);
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < n; i++)
        {
            if(cur < truckSize)
            {
                 cur += boxTypes[i][0];
                 ans += boxTypes[i][0] * boxTypes[i][1];   
            }
            if(cur >= truckSize)
            {
                int diff = cur - truckSize;
                ans -= diff *  boxTypes[i][1];   
                break;
            }
        }
        return ans;
    }
};
// tc o(nlogn)
// sc o(1)
