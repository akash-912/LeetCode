class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int vowel_count = 0;
        string ans = "";
        while(i<n&&s[i]!=' '){
            if(isVowel(s[i])){
                vowel_count++;
            }
            ans += s[i];
            i++;
        }
        if(i==n) return ans;
        i++;
        ans += ' ';
        while(i<n){
            int count = 0;
            string word = "";
            while(s[i]!=' '&&i<n){
                if(isVowel(s[i])){
                    count++;
                }
                word += s[i];
                i++;
            }
            if(count==vowel_count) reverse(word.begin(),word.end());
            ans += word;
            if(i<n) ans += ' ';
            i++;
        }
        return ans;
    }
};