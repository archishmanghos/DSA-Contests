import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC271 {
    public static String encode(List<String> strs) {
        StringBuilder encoded_string = new StringBuilder();
        for (String s : strs) {
            for (int i = 0; i < s.length(); i++) {
                int ch = s.charAt(i);
                encoded_string.append(ch);
                encoded_string.append('-');
            }
            encoded_string.append("-");
        }

        return encoded_string.toString();
    }

    public static List<String> decode(String str) {
        StringBuilder s = new StringBuilder();
        StringBuilder now = new StringBuilder();
        List<String> answer = new ArrayList<>();
        for (int i = 0; i < str.length() - 1; ) {
            now.setLength(0);
            do {
                now.append(str.charAt(i));
                i++;
            } while (str.charAt(i) != '-');

            char ch = (char) Integer.parseInt(now.toString());
            s.append(ch);

            if (str.substring(i, i + 2).compareTo("--") == 0) {
                answer.add(s.toString());
                s.setLength(0);
                i += 2;
            } else i++;
        }

        return answer;
    }
}