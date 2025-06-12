class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int diff=INT_MIN;int n=nums.size();

        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])>diff){
                diff=abs(nums[i]-nums[i-1]);
            }
        }
        return max(diff,abs(nums[0]-nums[n-1]));
    }
};