//https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> max;
        for(auto x:points)
        {
            int d = (x[0]*x[0]) + (x[1]*x[1]);
            max.push({d,{x[0],x[1]}});
            if(max.size()>k)    
                max.pop();
        }
        vector<vector<int>> ans;
        while(!max.empty())
        {
            vector<int> t={max.top().second.first,max.top().second.second};
            ans.push_back(t);
            max.pop();
        }
        return ans;
    }
};