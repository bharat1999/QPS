// https://leetcode.com/problems/dota2-senate/

class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r,d;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='D')
                d.push(i);
            else
                r.push(i);
        }
        while(true)
        {
            if(r.empty()) return "Dire";
            if(d.empty()) return "Radiant";
            int ridx=r.front();
            int didx=d.front();
            r.pop();
            d.pop();
            if(ridx<didx)
                r.push(ridx+n);
            else
                d.push(didx+n);
        }
        return "";
    }
};