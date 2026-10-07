class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int maxAns = Integer.MIN_VALUE;
        int left = 0;
        for(int right = 0;right<s.length();right++){
            char curChar = s.charAt(right);

            while(set.contains(curChar)){
                set.remove(s.charAt(left));
                left++;
            }
            set.add(curChar);
            maxAns = Math.max(maxAns,right-left+1);
        }
        return maxAns==Integer.MIN_VALUE?0:maxAns;
    }
}