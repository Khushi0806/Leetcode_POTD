class Solution {
public:
    int max(vector<int>& arr){
        int maxi=INT_MIN;
        for(auto it: arr){
            if(it>maxi) maxi=it;
        }
        return maxi;
    }
    int findLucky(vector<int>& arr) {
        vector<int> freq(max(arr),0);
        vector<int>ans;
        for(auto it: arr){
            freq[it]++;
        }
        for(auto it: arr){
            if(it==freq[it]){
                ans.push_back(it);
            }
        }
        int f=max(ans);
        if(f>0){
            return f;
        }
        else{
            return -1;
        }
    }
};