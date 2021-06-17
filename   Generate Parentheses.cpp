class Solution {
public:
    void fun(int open, int close, string op, vector<string>& ans)
    {

        if(open == 0 && close == 0)
        {
            ans.push_back(op);
            return;
        }
        if(open > 0)
        {
            string op1 = op;
            op1.push_back('(');
            fun(open - 1, close, op1, ans);
        }
        if(close > 0 && close > open)
        {
            string op2 = op;
            op2.push_back(')');
            fun(open, close - 1, op2, ans);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string>ans;
        int open = n, close = n;
        fun(open, close, "", ans);
        return ans;
    }
};