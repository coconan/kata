class Solution {
    public int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        } else {
            int prev1 = 1, prev2 = 1;
            for (int i = 3; i <= n; i++) {
                int cur = prev1 + prev2;
                prev2 = prev1;
                prev1 = cur;
            }
            return prev1;
        }
    }
}