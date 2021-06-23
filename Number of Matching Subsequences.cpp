class Solution {
public:
    bool is_subsequence(string str1, string str2, int n, int m)
    {
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(j == m)
        {
            return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int ans = 0;
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            if(is_subsequence(s, words[i], s.length(), words[i].length()) == true)
            {
                ans++;
            }
        }
        return ans;
    }
};

// TLE

class Solution {
public:
    bool is_subsequence(string str1, string str2, int n, int m)
    {
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(j == m)
        {
            return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int ans = 0;
        int n = words.size();
        unordered_map<string, bool>m;
        for(int i = 0; i < n; i++)
        { 
            if(m.find(words[i]) != m.end())
            {
              if(m[words[i]] == true)
              {
                  ans++;
              }
            }
            else
            {
                bool res = is_subsequence(s, words[i], s.length(), words[i].length());
                m[words[i]] = res;
                if(res == true)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
// ACCEPTED
// WE HAVE DONE SMALL OPTIMIZATION HERE USING THE HASHMAP, BY THIS FOR DUPLICATE STRINGS WE ARE DOING IN O(1) INSTEAD OF O(N*N)
