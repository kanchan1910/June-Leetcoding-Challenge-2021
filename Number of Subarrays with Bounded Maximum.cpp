class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n = nums.size();
        int ans = 0, prev = 0;
        int s = 0, e = 0;
        while(e < n)
        {
            if(nums[e] >= left && nums[e] <= right)
            {
                prev = e - s + 1;
                ans += prev;
            }
            else if(nums[e] < left)
            {
                ans += prev;
            }
            else if(nums[e] > right)
            {
                prev = 0;
                s = e + 1;
            }
            e++;
        }
        return ans;
    }
};
// tc o(n)

//   0  1  2  3
//  [2, 1, 4, 3]
//             s 
//             e
 
 
//  left = 2
//  right = 3
//  prev = 1
//  ans = 3
      
//       [2]
//       [2, 1]
//       [3]

//  0  1   2  3  4
// {2, 0, 11, 3, 0}
//            s
//               e
 
//  left = 1
//  right = 10
//  prev = 1
//  ans = 4
//      [2]
//      [2, 0]
//      [3]
//      [3, 0]
     
     
     
     
     // https://youtu.be/My3pobBPtbA
     
     // brute force 
     // generate all subaarays and then check their max value and accordingly calculate the count
     // tc o(n * n)
