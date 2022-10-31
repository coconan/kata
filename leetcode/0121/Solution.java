class Solution {
    public int maxProfit(int[] prices) {
        int min = 0, max = 0;
        int currentMin = 0, currentMax = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[currentMax] < prices[i]) {
                currentMax = i;
            }
            if (prices[currentMin] > prices[i]) {
                currentMin = i;
                currentMax = i;
            }
            if ((prices[currentMax] - prices[currentMin]) > (prices[max] - prices[min])) {
                min = currentMin;
                max = currentMax;
            }
        }
        return prices[max] - prices[min];
    }
}