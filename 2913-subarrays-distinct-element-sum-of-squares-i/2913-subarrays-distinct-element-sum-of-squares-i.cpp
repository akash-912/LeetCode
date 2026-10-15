class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            unordered_map<int,int> mpp;
            for(int j = i;j<n;j++){
                mpp[nums[j]];
                sum += (mpp.size()*mpp.size());
            }
        }
        return sum;
    }
};