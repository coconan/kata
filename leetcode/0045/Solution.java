class Solution {
    public int jump(int[] nums) {
        int[] minSteps = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            minSteps[i] = Integer.MAX_VALUE;
        }
        minSteps[0] = 0;
        for (int i = 0; i< nums.length; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i+j < nums.length) {
                    minSteps[i+j] = Math.min(minSteps[i+j], minSteps[i] + 1);
                }
            }
        }
        return minSteps[nums.length-1];
    }
}