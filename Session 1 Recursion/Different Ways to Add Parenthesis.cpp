//https://leetcode.com/problems/different-ways-to-add-parentheses/

/* **Tricky**

here we will break the string in two parts whenever we get a operator and than get all possible number from left and right and than use the operator to make an answer

ex 2 -1 +1

we get first expression - so we have to substring as 2 and 1+1

now when we traverse in left we will not find any operator add 2 to ans and return it

so current left vector = [2] 
now when we traverse right substr we get + so again recursively break left and right
as left = 1 right =1 . Now in both case we have only number so
we get left =1 and right =1 now we make all possible outcome of left and right using loop and opearate on them so here both have only 1 elements so we do 1 +1 and add it to ans 

now when we return this res it will be the right of first recursive call

so we get left = [2] and right = [2] 

so we traverse on them in loop to make add combination and add them to ans 

now current res = [0] 
But we will keep traversing original string and again break at + sign and process will repeat as 

ledt = 2 - 1 and right =1

here right part have only 1 value so it will give right=[1]

in left part we again break at -

so its left=[2] and right=[1]

so left of prev recursive call will be 2-1 =[1]

so now our left=[1] and right[1]

and our sign= + so we get 1 + 1= 2 and add it to res

So Finally res = [0,2]*/

class Solution {
    vector<int> solve(string &a,int s,int e)
    {
        vector<int> res;
        bool f=0;
        for(int i=s;i<=e;i++) 
        {
            if(a[i]=='+' or a[i]=='-' or a[i]=='*')
            {
                f=1;
                vector<int> left=solve(a,s,i-1); 
                vector<int> right=solve(a,i+1,e); 
                for(auto l:left) 
                {
                    int ans;
                    for(auto r:right)
                    {
                        
                        if(a[i]=='+')
                            ans=l+r;
                        else if(a[i]=='-')
                            ans=l-r;
                        else
                            ans=l*r;
                    res.push_back(ans); // push that combination
                    }
                }
            }
        }
        if(f==0) // if only one elemenet in substring we push that number
        {
            res.push_back(stoi(a.substr(s,e-s+1)));
        }
        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res=solve(expression,0,expression.size()-1);
        return res;
    }
};