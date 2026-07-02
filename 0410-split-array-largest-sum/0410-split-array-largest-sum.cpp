class Solution {
public:
    bool canWePlace(vector<int>& nums,int sum,int k){
        int n = nums.size();
        int cnt = 1;
        int cntSum = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]>sum) return false;
            if(cntSum+nums[i]<=sum){
                cntSum += nums[i];
            }else{
                cnt++;
                cntSum = nums[i];
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;
        int total = 0;
        int maxBook = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            maxBook = max(maxBook, nums[i]);
        }
        int low = maxBook;
        int high = total;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(canWePlace(nums,mid,k)){
                high = mid - 1;
            }else low = mid + 1;
        }
        return low;
    }
};