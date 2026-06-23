class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            if(nums1[i]%2!=0){
                minOdd = min(minOdd,nums1[i]);
            }
        }
        if(minOdd==INT_MAX) return true;
        for(int i = 0;i<n;i++){
            if(nums1[i]%2==0&&nums1[i]-minOdd<1){
                return false;
            }
        }
        return true;
    }
};