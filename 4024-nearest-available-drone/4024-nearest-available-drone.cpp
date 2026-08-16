class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int min_ind = INT_MAX;
        int min_range = INT_MAX;
        int n = drones.size();
        for(int i = 0;i<n;i++){
            int range = abs(drones[i][0]-target[0]);
            range += abs(drones[i][1]-target[1]);
            if(range<=drones[i][2]){
                if(range<min_range){
                    min_ind = i;
                    min_range = range;
                }
            }
        }
        return min_ind==INT_MAX? -1 : min_ind;
    }
};