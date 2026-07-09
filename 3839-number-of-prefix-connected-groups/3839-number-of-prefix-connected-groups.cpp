class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        int n = words.size();
        for(int i = 0;i<n;i++){
            if(k>words[i].size()){
                continue;
            }
            int m = 0;
            string s = "";
            while(m<k){
                s += words[i][m];
                m++;
            }
            mpp[s]++;
        }
        int count = 0;
        for(auto& it: mpp){
            if(it.second>=2){
                count++;
            }
        }
        return count;
    }
};