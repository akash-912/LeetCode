class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto l:nums){
            maxi = max(maxi,l);
            mini = min(mini,l);
        }
        return max(0,maxi-mini- 2*k);
    }
};