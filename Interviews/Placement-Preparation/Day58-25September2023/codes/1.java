public class LC389 {
    public char findTheDifference(String s, String t) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[(int) s.charAt(i) - 97]--;
            count[(int) t.charAt(i) - 97]++;
        }

        count[(int) t.charAt(t.length() - 1) - 97]++;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 1) return (char) (i + 97);
        }

        return '0';
    }
}