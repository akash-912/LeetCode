class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 0;
        int end = n - 1;
        int ans = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(n-mid==citations[mid]){
                return n - mid;
            }else if(citations[mid]>n-mid){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return n-start;
    }
};