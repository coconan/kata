class Solution {
    static HashMap<String, String> letterMap = new HashMap<>();
    {
        letterMap.put("2", "abc");
        letterMap.put("3", "def");
        letterMap.put("4", "ghi");
        letterMap.put("5", "jkl");
        letterMap.put("6", "mno");
        letterMap.put("7", "pqrs");
        letterMap.put("8", "tuv");
        letterMap.put("9", "wxyz");
    }
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return new ArrayList<>();
        }
        if (digits.length() == 1) {
            List<String> letters = new ArrayList<>();
            String s  = letterMap.get(digits);
            for (int i = 0; i < s.length(); i++) {
                letters.add(s.charAt(i) + "");
            }
            return letters;
        }
        List<String> subletters = letterCombinations(digits.substring(1));
        List<String> letters = new ArrayList<>();
        String s  = letterMap.get(digits.substring(0, 1));
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < subletters.size(); j++) {
                letters.add(s.charAt(i) + subletters.get(j));
            }
        }
        return letters;
    }
}