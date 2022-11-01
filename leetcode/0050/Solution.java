class Solution {
    public double myPow(double x, int n) {
        double result = 1.0;
        
        while (n != 0) {
            if (n%2 != 0) {
                result = n < 0 ? result / x : result * x;
            }
            x = x*x;
            n = n / 2;
        }
        
        return result;
    }
}