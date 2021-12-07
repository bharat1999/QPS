// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        vector<int> ans;
        for(auto x:a)
        {
            if(x>0)
                st.push(x);
            else
            {
                bool cur=true;
                while(!st.empty() and st.top()>0)
                {
                    if(st.top()<abs(x))
                        st.pop();
                    else if(st.top()==abs(x)) // means cur will not be pushed 
                        // as both have same value so both will be deleted
                    {
                        cur=false;
                        st.pop();
                        break;
                    }
                    else // if cur is small than top it should not be pushed
                    {
                        cur=false;
                        break;
                    }
                }
                if(cur==true)
                    st.push(x);
            }
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};