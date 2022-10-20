class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j += 2 * numRows - 2) {
                if (j+i < s.length()) {
                    sb.append(s.charAt(j+i));
                    if (0 < i && i < numRows - 1 && (j + i + (2 * (numRows - i) - 2)) < s.length()) {
                        sb.append(s.charAt(j+i+ (2 * (numRows - i) - 2)));
                    }
                }
            }
        }
        return sb.toString();
    }
}