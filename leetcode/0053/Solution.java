class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int[] maxSums = new int[nums.length];
        maxSums[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            maxSums[i] = Math.max(nums[i], nums[i] + maxSums[i-1]);
            max = Math.max(maxSums[i], max);
        }
        return max;
    }
}