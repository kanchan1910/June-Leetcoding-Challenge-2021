class MyCalendar
{
public:
    vector<pair<int, int>>v;
    MyCalendar()
    {
        
    }
    
    bool book(int start, int end) 
    {
        for(auto x: v)
        {
            if(max(start, x.first) < min(end, x.second))
            {
                return false;
            }
        }
        v.push_back({start, end});
        return true;
    }
};
