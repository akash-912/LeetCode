class Solution {
    public String restoreString(String s, int[] indices) {
        int n = indices.length;
        char[] arr = new char[n];
        for(int i = 0;i<n;i++){
            char ch = s.charAt(i);
            arr[indices[i]] = ch;
        }
        return new String(arr);
    }
}