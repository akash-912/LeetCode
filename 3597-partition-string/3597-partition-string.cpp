class Solution {
public:
    vector<string> partitionString(string s) {
        bool curr_seen = false;
        unordered_map<string,int> mpp;
        string ans = "";
        vector<string> output;
        for(auto& ch:s){
            ans += ch;
            if(mpp.find(ans)!=mpp.end()) continue;
            output.push_back(ans);
            mpp[ans]++;
            ans = "";
        }
        return output;
    }
};