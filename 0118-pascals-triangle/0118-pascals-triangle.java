class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> output = new ArrayList<>();
        for(int i = 0;i<numRows;i++){
            ArrayList<Integer> ans = new ArrayList<>();
            int ncr = 1;
            ans.add(ncr);
            for(int j = 0;j<i;j++){
                ncr = ncr*(i-j);
                ncr = ncr/(j+1);
                ans.add(ncr);
            }
            output.add(ans);
        }
        return output;
    }
}