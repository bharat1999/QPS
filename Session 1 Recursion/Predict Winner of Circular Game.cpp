//https://leetcode.com/problems/find-the-winner-of-the-circular-game/


/*   **Tricky**

here the we will calculate answer with 0 indexing and in the end add 1 because that will help us reduce the relation.

now lets think of base case when n=1 whatever be the value of k 0 is the answer

now when n=2 answer will be (0+k)%2

because if k =1 
0 index player will be eliminated so 0 + 1 = 1 % 2 = 1 , so 1st index palyer will survive

So for n = 3 

answer will (f(2) +k) %3

so take example of k=2 and n=3

so our call wiil be 1 + f(3,2)

1st call n=3 , k =2 . n!=1 so base case not hit
so call (f(2,2)+2)%3

2nd call n=2 k=2

again base case not hit 

so call (f(1,2)+2)%2

3rd call n=1 k=2 base case hit it will return 0 as winner

now 0 is returned to 2nd call so 

it become (0+2)%2 which will return 0 bcz in case of two people and k=2 , index 1 player will be eliminated

Now we return to final call

so it become (0+2)%3 = 2 which is true in case of 3 people and k=2 , only index 2 will survive not it will return to main as our answer is in 0 indexing we add 1 and return it.*/

class Solution {
    int solve(int n,int k)
    {
        if(n==1)
            return 0;
        return (solve(n-1,k)+k)%n;
    }
    public:
    int findTheWinner(int n, int k) {
        return 1+solve(n,k);
        
    }
};