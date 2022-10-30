class Solution {
    public int getMaxLen(int[] nums) {
        int n = nums.length;
        int[] negatives = new int[n];
        int[] positives = new int[n];
        negatives[0] = nums[0] == 0 ? 0 : (nums[0] > 0 ? 0 : 1);
        positives[0] = nums[0] == 0 ? 0 : (nums[0] > 0 ? 1 : 0);
        int max = positives[0];
        for (int i = 1; i < n; i++) {
            negatives[i] = nums[i] == 0 ? 0
                : (nums[i] > 0 ? (negatives[i-1] == 0 ? 0 : negatives[i-1] + 1)
                   : positives[i-1] + 1);
            positives[i] = nums[i] == 0 ? 0
                : (nums[i] > 0 ? positives[i-1] + 1
                   : (negatives[i-1] == 0 ? 0 : negatives[i-1] + 1));
            max = Math.max(max, positives[i]);
        }
        return max;
    }
}