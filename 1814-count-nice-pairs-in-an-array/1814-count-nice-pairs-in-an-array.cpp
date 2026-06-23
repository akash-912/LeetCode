class Solution {
public:
    int rev(int num){
        int r = 0;
        while(num>0){
            r = r*10 + num%10;
            num = num/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        int count = 0;
        unordered_map<long long,int> mpp;
        for(int i = 0;i<n;i++){
            int diff = nums[i] - rev(nums[i]);
            count = (count + mpp[diff])%MOD;
            mpp[diff]++;
        }
        return count;
    }
};