class Solution {
    public:
        int length(int n){
            int len=0;
            while(n!=0){
                int p=n%10;
                n=n/10;
                len++;
            }
        return len;
        }
        int findNumbers(vector<int>& nums) {
            int count=0;
            for(int i : nums){
                if(length(i)%2==0){
                    count++;
                }
            }
            return count;
        }
    };