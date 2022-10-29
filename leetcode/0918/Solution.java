class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int[] maxSum = new int[nums.length];
        int[] minSum = new int[nums.length];
        maxSum[0] = nums[0];
        minSum[0] = nums[0];
        int max = nums[0];
        int min = nums[0];
        int minSumIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            maxSum[i] = Math.max(maxSum[i-1] + nums[i], nums[i]);
            max = Math.max(maxSum[i], max); 
            minSum[i] = Math.min(minSum[i-1] + nums[i], nums[i]);
            if (min > minSum[i]) {
                min = minSum[i];
                minSumIndex = i;
            }
        }
        if (n == 1) {
            return max;
        }
        int minIndex = minSumIndex;
        maxSum[minIndex] = nums[minIndex];
        for (int i = (minIndex + 1) % n; i%n != minIndex; i++) {
            maxSum[i % n] = Math.max(maxSum[((i+n)-1) % n] + nums[i%n], nums[i%n]);
            max = Math.max(maxSum[i%n], max);
        }
        return max;
    }
}