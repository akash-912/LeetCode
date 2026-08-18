class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int largest = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            largest = max(largest,nums[i]);
            mpp[nums[i]]++;
        }
        if(k==n) return largest;
        if(k>1&&k<n){
            int a = nums[0];
            int b = nums[n-1];
            if(mpp[a]>1&&mpp[b]>1){
                return -1;
            }
            if(mpp[a]>1){
                return b;
            }
            if(mpp[b]>1){
                return a;
            }
            if(a>b){
                return a;
            }
            return b;
        }
        int maxi = -1;
        if(k==1){
            for(int i = 0; i < n; i++){
                if(mpp[nums[i]]==1){
                    maxi = max(maxi,nums[i]);
                }
            }
        }
        return maxi;
    }
};