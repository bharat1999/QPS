// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> s;
        vector<int> ans(t.size());
        s.push({t[0],0});
        for(int i=1;i<t.size();i++)
        {
            if(t[i]<s.top().first)
                s.push({t[i],i});
            else
            {
                while(!s.empty() and s.top().first<t[i])
                {
                    ans[s.top().second]=i-s.top().second;
                    s.pop();
                }
                s.push({t[i],i});
            }
        }
        return ans;
    }
};