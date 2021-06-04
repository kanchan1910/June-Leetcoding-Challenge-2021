class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxheight = max(h - horizontalCuts[horizontalCuts.size() - 1], horizontalCuts[0] - 0);
        for(int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            maxheight = max(maxheight, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        int maxwidth = max(w - verticalCuts[verticalCuts.size() - 1], verticalCuts[0] - 0);
        for(int i = 0; i < verticalCuts.size() - 1; i++)
        {
        maxwidth = max(maxwidth, verticalCuts[i + 1] - verticalCuts[i]);
        }
        // cout << maxheight << " " << maxwidth << endl;
        long ans = 1L * maxheight * maxwidth;
        return (int)(ans % 1000000007);
    }
};
// tc o(hlogh + wlogw)
// sc o(1)


// brute force 
// tc o(h * w) + o(hlogh + wlogw)
// for checking each pair
 
