class Solution {
    public int maxArea(int[] height) {
        int[] maxIndex = new int[10001];
        int[] minIndex = new int[10001];
        for (int i = 0; i < maxIndex.length; i++) {
            maxIndex[i] = Integer.MIN_VALUE;
            minIndex[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < height.length; i++) {
            if (i > maxIndex[height[i]]) {
                maxIndex[height[i]] = i;
            }
            if (i < minIndex[height[i]]) {
                minIndex[height[i]] = i;
            }
        }
        for (int i = maxIndex.length-2; i >= 0; i--) {
            if (maxIndex[i] < maxIndex[i+1]) {
                maxIndex[i] = maxIndex[i+1];
            }
            if (minIndex[i] > minIndex[i+1]) {
                minIndex[i] = minIndex[i+1];
            }
        }
        int max = 0;
        for (int i = maxIndex.length-1; i >= 0; i--) {
            if (maxIndex[i] != Integer.MIN_VALUE && minIndex[i] != Integer.MAX_VALUE
                && i * (maxIndex[i] - minIndex[i]) > max) {
                max = i * (maxIndex[i] - minIndex[i]);
            }
        }
        return max;
    }
}