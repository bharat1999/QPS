//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(auto x:mp)
        {
            heap.push({x.second,x.first}); // first is freq and second is value
            if(heap.size()>k)
                heap.pop();
        }
        vector<int> res;
        while(!heap.empty())
        {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};