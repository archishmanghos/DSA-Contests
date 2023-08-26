public class LC2262 {
    public static long appealSum(String s) {
        int n = s.length();
        long answer = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int totalSubstrings = n * (n + 1) / 2, prev = -1;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == c) {
                    int characters_between = (i - prev - 1);
                    totalSubstrings -= characters_between * (characters_between + 1) / 2;
                    prev = i;
                }
            }
            int characters_between = (n - prev - 1);
            totalSubstrings -= characters_between * (characters_between + 1) / 2;
            answer += totalSubstrings;
        }

        return answer;
    }
}
