class Solution {
    int[][] memo;
    public int maxProfit(int[] prices) {
        int n = prices.length;
        memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }
        return maxProfitAux(prices, 0, prices.length);
    }
    
    public int maxProfitAux(int[] prices, int start, int end) {
        if (start >= end-1) {
            return 0; 
        }
        if (memo[start][end-1] != -1) {
            return memo[start][end-1];
        }
        if (start == end-2) {
            memo[start][end-1] = Math.max(0, prices[end-1] - prices[start]);
            return memo[start][end-1];
        }
        int max = 0;
        for (int i = start; i < end; i++) {
            max = Math.max(max, maxProfitAux(prices, start, i) + maxProfitAux(prices, i+1, end));
        }
        memo[start][end-1] = Math.max(max, prices[end-1] - prices[start]);
        return memo[start][end-1];
    }
}

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
