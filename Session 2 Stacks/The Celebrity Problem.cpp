// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++)
            s.push(i);
        while(s.size()>1)
        {
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            if(v[i][j] == 1)
            {
                s.push(j);
            }
            else
            {
                s.push(i);
            }
        }
        int cand = s.top();
        for(int i=0; i<n; i++)
        {
            if(i!=cand)
            {
                if(v[cand][i] == 1 || v[i][cand]==0)
                {
                    return -1;
                }
            }
        }
        return cand;
    }
};