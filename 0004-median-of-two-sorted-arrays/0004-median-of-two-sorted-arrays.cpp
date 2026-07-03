class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        vector<int> nums = nums1;
        for(auto& num:nums2){
            nums.push_back(num);
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n%2==0){
            ans = ((double)nums[n/2] + (double)nums[n/2 - 1])/2.0;
        }else{
            ans = (double)nums[n/2];
        }
        return ans;
    }
};