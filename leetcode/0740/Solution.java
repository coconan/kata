class Solution {
    public int deleteAndEarn(int[] nums) {
        int[] pointCount = new int[10001];
        int maxPoint = 0;
        for (int i = 0; i < nums.length; i++) {
            pointCount[nums[i]]++;
            if (nums[i] > maxPoint) {
                maxPoint = nums[i];
            }
        }
        int[] maxPoints = new int[maxPoint + 1];
        maxPoints[0] = 0;
        maxPoints[1] = pointCount[1];
        for (int i = 2; i < maxPoint + 1; i++) {
            maxPoints[i] = Math.max(maxPoints[i-2] + pointCount[i] * i, maxPoints[i-1]);
        }
        return maxPoints[maxPoint];
    }
}
