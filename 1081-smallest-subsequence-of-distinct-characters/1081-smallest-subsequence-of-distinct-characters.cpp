class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        int n = s.size();
        for(auto ch: s){
            freq[ch-'a']++;
        }
        string ans = "";
        vector<bool> vis(26,false);
        for(int i = 0;i<n;i++){
            freq[s[i]-'a']--;
            if(vis[s[i]-'a']) continue;
            while(!ans.empty()&&ans.back()>s[i]&&freq[ans.back()-'a']>0){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]-'a'] = true;
        }
        return ans;
    }
};