class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int max = values[1] + values[0] - 1;
        for (int i = 0; i < values.length; i++) {
            for (int j = i + 1; j < values.length && j < i + values[i]; j++) {
                if (max < (values[i] + values[j] + i - j)) {
                    max = (values[i] + values[j] + i - j);
                }
            }
        }
        return max;
    }
}