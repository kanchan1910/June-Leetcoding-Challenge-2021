class Solution {
public:
    vector<string>get_neighbours(string str)
    {
        vector<string>tmp;
        for(int i = 0; i < 4; i++)
        {
            string str1 = str, str2 = str;
            str1[i] = (str1[i] == '9') ? '0' : str1[i] + 1;
            str2[i] = (str2[i] == '0') ? '9' : str2[i] - 1;
            tmp.push_back(str1);
            tmp.push_back(str2);
        }
        return tmp;
    }
    int openLock(vector<string>& deadends, string target)
    {
        if("0000" == target)
        {
            return 0;
        }
        unordered_set<string>s;
        int n = deadends.size();
        for(int i = 0; i < n; i++)
        {
            s.insert(deadends[i]);
        }
        if(s.find("0000") != s.end())
        {
            return -1;
        }
        queue<string>q;
        q.push("0000");
        s.insert("0000");
        int level = 0;
        while(q.size() > 0)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string str = q.front();
                if(str == target)
                {
                    return level;
                }
                q.pop();
                vector<string>v = get_neighbours(str);
                for(auto x: v)
                {
                    if(s.find(x) == s.end())
                    {
                        s.insert(x);
                        q.push(x);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
