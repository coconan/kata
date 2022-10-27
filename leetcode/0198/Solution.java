class Solution {
    public int rob(int[] nums) {
        int maxAmount[] = new int[nums.length];
        maxAmount[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            maxAmount[i] = Math.max(maxAmount[i-1], (i-2 < 0 ? 0 : maxAmount[i-2]) + nums[i]);
        }
        return maxAmount[nums.length-1];
    }
}