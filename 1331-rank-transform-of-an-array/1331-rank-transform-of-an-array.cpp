class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        int n = arr.size();
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            pq.push({arr[i],i});
        }
        int rank = 0;
        int prev = INT_MIN;
        while(!pq.empty()){
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(prev==num){
                ans[idx] = rank;
            }else{
                ans[idx] = ++rank;
            }
            prev = num;
        }
        return ans;
    }
};