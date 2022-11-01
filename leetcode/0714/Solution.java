class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] cooldown = new int[n];
        int[] buy = new int[n];
        int[] sell = new int[n];
        cooldown[0] = 0;
        buy[0] = -prices[0];
        sell[0] = Integer.MIN_VALUE;
        for (int i = 1; i < n; i++) {
            cooldown[i] = Math.max(sell[i-1], cooldown[i-1]);
            buy[i] = Math.max(buy[i-1], cooldown[i-1]-prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }
        return Math.max(sell[n-1], cooldown[n-1]);
    }
}



class Solution {
    public int maxProfit(int[] prices, int fee) {
        int sell = 0;
        int buy = Integer.MIN_VALUE;
        for (int i = 0; i < prices.length; i++) {
            if (sell < buy + prices[i]) {
                sell = buy + prices[i];
            } else if (buy < sell - prices[i] - fee) {
                buy = sell - prices[i] - fee;
            }
        }
        return sell;
    }
}