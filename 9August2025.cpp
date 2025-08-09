class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return 1;
        if(n%2!=0) return 0; 
        else return n>0 && ((n&(n-1))==0);
    }
};
