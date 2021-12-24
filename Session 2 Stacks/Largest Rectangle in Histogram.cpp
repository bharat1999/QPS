// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int i,ns[100005],ps[100005];
        int n=h.size();
        for(i=0;i<n;i++)
        {
            while(!s.empty() and h[s.top()]>h[i])
            {
                ns[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            ns[s.top()]=n;
            s.pop();
        }
        ps[0]=-1;
        s.push(0);
        for(i=1;i<n;i++)
        {
            while(!s.empty() and h[s.top()]>=h[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ps[i]=s.top();
            }
            else
            {
                ps[i]=-1;
            }
            s.push(i);
        }
        long int maxarea=0,area;
        for(i=0;i<n;i++)
        {
            int b=ns[i] - ps[i] -1;
            int l= h[i];
            area=l*b;
            maxarea=max(area,maxarea);
        }
    return maxarea;
    }
};