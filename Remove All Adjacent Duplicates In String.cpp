class Solution {
public:
    string removeDuplicates(string s) 
    {
        int n = s.length();
        if(n == 1)
        {
            return s;
        }
        stack<char>ss;
        for(int i = 0; i < n; i++)
        {
            if(ss.empty())
            {
                ss.push(s[i]);
            }
            else
            {
                if(ss.top() == s[i])
                {
                    ss.pop();
                }
                else
                {
                    ss.push(s[i]);
                }
            }
        }
        string ans = "";
        while(!ss.empty())
        {
            ans += ss.top();
            ss.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// tc o(n)
// sc o(n)
