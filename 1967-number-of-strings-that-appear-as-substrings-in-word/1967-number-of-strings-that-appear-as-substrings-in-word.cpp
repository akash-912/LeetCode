class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> mpp;
        int n = word.size();
        for(int i = 0;i<n;i++){
            string temp = "";
            for(int j = i;j<n;j++){
                temp += word[j];
                mpp[temp]++;
            }
        }
        int count = 0;
        for(auto& it:patterns){
            if(mpp[it]>0) count++;
        }
        return count;
    }
};