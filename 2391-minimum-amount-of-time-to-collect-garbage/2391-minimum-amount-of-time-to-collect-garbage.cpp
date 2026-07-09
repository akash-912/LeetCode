class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal = 0;
        int paper = 0;
        int glass = 0;
        int m_idx = 0;
        int p_idx = 0;
        int g_idx = 0;
        int n = garbage.size();
        for(int i = 0;i<n;i++){
            for(auto& ch: garbage[i]){
                if(ch=='M'){
                    metal++;
                    m_idx = i;
                }
                else if(ch=='G'){
                    glass++;
                    g_idx = i;
                }else{
                    paper++;
                    p_idx = i;
                }
            }
        }
        int ans = 0;
        ans = metal + paper + glass;
        for(int i = 0;i<m_idx;i++){
            ans += travel[i];
        }
        for(int i = 0;i<g_idx;i++){
            ans += travel[i];
        }
        for(int i = 0;i<p_idx;i++){
            ans += travel[i];
        }
        return ans;
    }
};