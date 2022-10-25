class Solution {
    public String intToRoman(int num) {
        StringBuilder result = new StringBuilder();
        if (num / 1000 > 0) {
            result.append(nString(num/1000, "M"));
            num = num % 1000;
        }
        if (num / 100 > 0) {
            if (num / 100 == 9) {
                result.append("CM");
            } else if (num / 100 == 4) {
                result.append("CD");
            } else if (num / 100 >= 5) {
                result.append("D");
                result.append(nString((num-500) / 100, "C"));
            } else {
                result.append(nString(num / 100, "C"));
            }
            num = num % 100;
        }
        
        if (num / 10 > 0) {
            if (num / 10 == 9) {
                result.append("XC");
            } else if (num / 10 == 4) {
                result.append("XL");
            } else if (num / 10 >= 5) {
                result.append("L");
                result.append(nString((num-50) / 10, "X"));
            } else {
                result.append(nString(num / 10, "X"));
            }
            num = num % 10;
        }
        
        
        if (num / 1 > 0) {
            if (num / 1 == 9) {
                result.append("IX");
            } else if (num / 1 == 4) {
                result.append("IV");
            } else if (num / 1 >= 5) {
                result.append("V");
                result.append(nString((num-5) / 1, "I"));
            } else {
                result.append(nString(num / 1, "I"));
            }
        }
        return result.toString();
    }
    
    String nString(int n, String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(s);
        }
        return sb.toString();
    }
}
