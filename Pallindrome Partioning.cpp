//https://leetcode.com/problems/palindrome-partitioning/

class Solution {
    vector<vector<string>> ans;
    bool isPallindrome(string a)
    {
        int s=0,e=a.length()-1;
        while(s<e)
        {
            if(a[s]!=a[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
    void solve(string &a,int s,vector<string> &curr_ans)
    {
        if(s==a.size())
        {
            ans.push_back(curr_ans);   
            return;
        }
        for(int end=s;end<=a.size();end++)
        {
            string sub=a.substr(s,end-s+1);
            if(isPallindrome(sub))
            {
                curr_ans.push_back(sub);
                solve(a,end+1,curr_ans);
                curr_ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr_ans;
        solve(s,0,curr_ans);
        return ans;
    }
};