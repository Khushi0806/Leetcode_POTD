class Solution {
public:
    int maximumDifference(vector<int>& nums) {
      int diff=INT_MIN;
      for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]-nums[i]>diff){
                diff=nums[j]-nums[i];
            }
        }
      }
      if(diff<=0){
        return -1;
      }
      return diff;  
    }
};