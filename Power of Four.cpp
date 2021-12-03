//https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n==0)
            return false;
        if(n%4==0)
            return isPowerOfFour(n/4);
        return false;
    }
};