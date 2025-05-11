class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool ans=false;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i-1]%2==1 && arr[i]%2==1 && arr[i+1]%2==1){
                ans=true;
                return ans;
            }
        }
        return ans;
    }
};