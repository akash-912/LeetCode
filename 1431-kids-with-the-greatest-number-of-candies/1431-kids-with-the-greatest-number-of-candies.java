class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxNum = Integer.MIN_VALUE;
        int n = candies.length;
        for(int i = 0;i<n;i++){
            maxNum = Math.max(maxNum,candies[i]);
        }
        List<Boolean> arr = new ArrayList<>();
        for(int candy: candies){
            arr.add(candy+extraCandies>=maxNum);
        }
        return arr;
    }
}