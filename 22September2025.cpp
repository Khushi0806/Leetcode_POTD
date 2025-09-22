class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int it: nums){
            freq[it]++;
        }
        
        int tar = 0;
        for(auto &p: freq){
            tar = max(tar, p.second);
        }
        
        int ans = 0;
        for(auto &p: freq){
            if(p.second == tar){
                ans += p.second; // add all occurrences, not just 1
            }
        }
        return ans;
    }
};
