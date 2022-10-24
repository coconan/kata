class Solution {
    public int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int before = result;
            result = 0;
            for (int i = 0; i < 10; i++) {
                result += before;
                if ((before < 0 && result > before) || (before > 0 && result < before)) {
                    return 0;
                }
            }
            result = result + x % 10;
            if ((before < 0 && result > before) || (before > 0 && result < before)) {
                return 0;
            }
            x = x / 10;
        }
        return result;
    }
}