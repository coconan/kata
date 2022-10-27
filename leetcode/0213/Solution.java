class Solution {
    public int rob(int[] nums) {
        int[] includeFirstMaxAmount = new int[nums.length];
        int[] excludeFirstMaxAmount = new int[nums.length];
        includeFirstMaxAmount[0] = nums[0];
        excludeFirstMaxAmount[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            includeFirstMaxAmount[i] = Math.max(
                includeFirstMaxAmount[i-1],
                (i == nums.length - 1 ? 0 : nums[i]) + (i - 2 < 0 ? 0 : includeFirstMaxAmount[i-2]));
            excludeFirstMaxAmount[i] = Math.max(
                excludeFirstMaxAmount[i-1],
                nums[i] + (i - 2 < 0 ? 0 : excludeFirstMaxAmount[i-2]));
        }
        return Math.max(excludeFirstMaxAmount[nums.length-1], includeFirstMaxAmount[nums.length-1]);
    }
}