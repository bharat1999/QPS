//https://leetcode.com/problems/predict-the-winner/


/* **Explanation**

Here we are assuming both player play optimally . Greedy cannot work here because always first choosing the biggest number is not valid

For example

1 5 101 9

If we optimally choose 9 than opponent can choose 101 ,so greedy fails.

So here we have to consider both case if we choose the first or last element from current range.

let we have a array of size 4 initially s=0 and e=3; 

**If Player 1 choose Sth element**

Player 2 have 2 choice to select from (s+1,e)

a. If player 2 choose s+1 element we have left array from (s+2,e) 
b. If we player 2 choose e element than player 1 will be left to choose from (s+1,e-1)

**If Player 1 choose Eth element**

Player 2 have 2 choice to select from (s,e-1)

a. If player 2 choose s element we have left array from (s+1,e-1) 
b. If we player 2 choose e-1 element than player 1 will be left to choose from (s,e-2)

So we can calcualate both possibilty adn take max , 

But catch here is that player 2 will also play optimally and will give us to choose from minimum so we will take min of the 2 cases

so recursive relation is

startsum = arr[s] + min(f(s+2,e),f(s+1,e-1)
endsum = arr[e] + min(f(s,e-1),f(s,e-2)

and return max of this

now in main we get the max player 1 sum so to calculate player 2 sum we find total sum of array and subtract p1 max sum

and finally if  p1>p2?return true:return false;*/

class Solution {
   int solve(vector<int> &nums ,int s,int e)
   {
       if(s>e)
           return 0;
       // if player 1 choose s
       int opt1 = nums[s]+min(solve(nums,s+2,e),solve(nums,s+1,e-1));
        // if player 2 choose e
        int opt2 = nums[e] +
           min(solve(nums,s+1,e-1),solve(nums,s,e-2));
        return max(opt1,opt2);   
   }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int p1=solve(nums,0,nums.size()-1);
        int p2=0;
        for(auto x:nums)
            p2+=x;
        p2-=p1;
        return p1>=p2;
    }
};