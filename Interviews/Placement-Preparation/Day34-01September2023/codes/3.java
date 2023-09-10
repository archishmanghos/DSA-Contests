import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> index = new HashMap<>();
        List<List<String>> answer = new ArrayList<>();

        for (String s : strs) {
            int[] count = new int[26];
            for (int i = 0; i < s.length(); i++) {
                int ch = (int)s.charAt(i) - 97;
                count[ch]++;
            }
            StringBuilder str = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    char ch = (char)(i + 97);
                    str.append(String.valueOf(ch).repeat(count[i]));
                }
            }

            String str_clone = str.toString();
            if (index.get(str_clone) == null) {
                answer.add(new ArrayList<>());
                index.put(str_clone, answer.size() - 1);
            }

            answer.get(index.get(str_clone)).add(s);
        }

        return answer;
    }
}