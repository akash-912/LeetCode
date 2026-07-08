class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<=j){
            int area = min(height[i],height[j])*(j-i);
            maxA = max(maxA,area);
            if(height[i]>height[j]){
                j--;
            }else i++;
        }
        return maxA;
    }
};