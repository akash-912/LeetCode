class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mpp(26,0);
        int n = s.size();
        int ind = 0;
        for(int i = 0;i<n;i++){
            mpp[s[i]-'a']++;
        }
        while(ind<n&&mpp[s[ind]-'a']>1){
            ind++;
        }
        if(ind==n) return -1;
        return ind;
    }
};