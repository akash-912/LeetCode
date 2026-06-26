class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int cumSum = 0;
        mpp[0] = 1;
        long long validLeftPoints = 0;
        long long result = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j]==target){
                validLeftPoints += mpp[cumSum];
                cumSum += 1;
            }else{
                cumSum -= 1;
                validLeftPoints -= mpp[cumSum];
            }
            mpp[cumSum] += 1;
            result += validLeftPoints;
        }
        return result;
    }
};