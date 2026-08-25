class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto c: nums){
            mpp[c]++;
        }
        int start = k;
        while(true){
            if(mpp.find(start)==mpp.end()){
                return start;
            }
            start = start + k;
        }
        return -1;
    }
};