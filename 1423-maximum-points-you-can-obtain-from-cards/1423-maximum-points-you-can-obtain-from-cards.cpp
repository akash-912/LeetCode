class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = n - k;
        int totalPoints = 0;
        int windowSum = 0;
        int maxPoints = 0;
        for(int i = 0;i<n;i++){
            totalPoints += cardPoints[i];
        }
        for(int i = 0;i<n-k;i++){
            windowSum += cardPoints[i];
        }
        maxPoints = max(maxPoints,totalPoints-windowSum);
        while(r<n){
            windowSum = windowSum + cardPoints[r] - cardPoints[l];
            maxPoints = max(maxPoints,totalPoints-windowSum);
            r++;
            l++;
        }
        return maxPoints;
    }
};