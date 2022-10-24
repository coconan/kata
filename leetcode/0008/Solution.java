class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        int result = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s.charAt(i) == '-') {
                sign = -1;
            } else if (i == 0 && s.charAt(i) == '+') {
                sign = 1;
            } else if ('0' <= s.charAt(i) && s.charAt(i) <= '9') {
                int before = result;
                result = 0;
                for (int j = 0; j < 10; j++) {
                    result += before;
                    if ((before < 0 && before < result) || (before > 0 && before > result)) {
                        return before > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                    }
                }
                result = result + ((before >= 0) ? (s.charAt(i) - '0') : ('0' - s.charAt(i)));
                if ((before < 0 && before < result) || (before > 0 && before > result)) {
                    return before > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                }
                if (sign != 0 && result != 0) {
                    result = result * sign;
                    sign = 0;
                }
            } else {
                break;
            }
        }
        return result;
    }
}