class Solution {
public:
    bool fun(string str)
    {
        for(int i = 0; i < str.length() / 2; i++)
        {
            if(str[i] != str[str.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>>ans;
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    string str = words[i] + words[j];
                    if(fun(str) == true)
                    {
                        vector<int>tmp({i, j});
                        ans.push_back(tmp);
                    }   
                }
            }
        }
        return ans;
    }
};
// tc o(n * n * k)
// sc (1)
// TLE






class Solution {
public:
     
    // Check if a string is palindrome
    bool isPalin(string s) 
    {
        int len = s.size();
        
        for(int i = 0; i< len/2; i++) 
        {
            
            if(s[i] != s[len-i-1])
            {
                return false;
            }
            
        }
        
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        /*
        When will s1+s2 be palindrome ?
        1. if s1 = "" and s2 is palin, then s1+s2 and s2+s1 are palindrome
        2. if s2 = reverse(s1), then s1+s2 and s2+s1 is palindrome
        3. if s1[0: cut] is palindrome and s2 = reverse(s1[cut+1:]), s2+s1 is palindrome
        4. if s1[cut+1:] is palindrome and s2 = reverse(s1[0:cut]), s1+s2 is palindrome
        */
        
        //first we save the word-index mapping in the hmap
        unordered_map<string, int> m;
        for(int i = 0; i< n; i++) 
        {
            m[words[i]] = i;
        }
        
        // case 1: if s1 is ""
        if(m.find("") != m.end()) 
        {
            int emptyStrIndex = m[""];
            
            for(int i = 0; i < n; i++) 
            {
                if(i == emptyStrIndex) 
                {
                  continue;   
                }
                if(isPalin(words[i]))
                {
                    ans.push_back({emptyStrIndex, i});
                    ans.push_back({i, emptyStrIndex});
                }
            }
        }
        
        // Case2:
        for(int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if(m.find(rev) != m.end()) 
            {
                int revIndex = m[rev];
                if(revIndex == i)
                {
                    continue;
                }
                ans.push_back({i,revIndex});
            }
        }
        
        
        for(int i = 0; i < n; i++) 
        {
            for(int cut = 1; cut < words[i].length(); cut++) {
                
                //Case 3:
                if(isPalin(words[i].substr(0, cut)))
                {
                    string rev = words[i].substr(cut);
                    reverse(rev.begin(), rev.end());
                    
                    if(m.find(rev) != m.end())
                    {
                        auto revIndex = m[rev];
                        if(revIndex == i)
                        {
                            continue;
                        }
                        ans.push_back({revIndex,i});
                    }
                }
                
              // Case 4: 
              if(isPalin(words[i].substr(cut)))
              {
                    string rev = words[i].substr(0, cut);
                    reverse(rev.begin(), rev.end());
                  
                    if(m.find(rev) != m.end())
                    {
                        auto revIndex = m[rev];
                        if(revIndex == i)
                        {
                            continue; 
                        }
                        ans.push_back({i,revIndex});
                    }
                }  
            }
        }
        
        return ans;
    }
};
// tc o(n * k * k)
// sc o(n)
// ACCEPTED
