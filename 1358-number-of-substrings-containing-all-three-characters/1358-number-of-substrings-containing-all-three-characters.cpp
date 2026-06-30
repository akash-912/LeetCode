class Solution {
public:
    int numberOfSubstrings(string s) {
        int r = 0;
        int n = s.size();
        long long count = 0;
        vector<int> lastSeen(3,-1);
        while(r<n){
            lastSeen[s[r]-'a'] = r;
            if(lastSeen[0]!=-1&&lastSeen[1]!=-1&&lastSeen[2]!=-1){
                count += 1 + min({lastSeen[0],lastSeen[1],lastSeen[2]});
            }
            r++;
        }
        return count;
    }
};































