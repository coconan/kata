import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> codeMap = new HashMap<>();
        codeMap.put('I', 1);
        codeMap.put('V', 5);
        codeMap.put('X', 10);
        codeMap.put('L', 50);
        codeMap.put('C', 100);
        codeMap.put('D', 500);
        codeMap.put('M', 1000);
        
        int result = 0;
        int lastCodeValue = 1000;
        for (int i = 0; i < s.length(); i++) {
            int codeValue = codeMap.get(s.charAt(i));
            if (codeValue > lastCodeValue) {
                result = result + codeValue - 2 * lastCodeValue;
            } else {
                result = result + codeValue;
            }
            lastCodeValue = codeValue;
        }
        return result;
    }
}