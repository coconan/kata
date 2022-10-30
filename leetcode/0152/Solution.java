class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int[] maxProds = new int[n];
        int[] minProds = new int[n];
        maxProds[0] = nums[0];
        minProds[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < n; i++) {
            minProds[i] = Math.min(nums[i], Math.min(minProds[i-1] * nums[i], maxProds[i-1] * nums[i]));
            maxProds[i] = Math.max(nums[i], Math.max(maxProds[i-1] * nums[i], minProds[i-1] * nums[i]));
            max = Math.max(max, maxProds[i]);
        }
        return max;
    }
}
