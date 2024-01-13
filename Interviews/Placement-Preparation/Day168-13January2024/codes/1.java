import java.util.ArrayList;
import java.util.List;

public class LC1347 {
    public int minSteps(String s, String t) {
        int[] origFreq = new int[30];
        int[] freq = new int[30];
        for (int i = 0; i < s.length(); i++) origFreq[(int) s.charAt(i) - 97]++;
        for (int i = 0; i < t.length(); i++) freq[(int) t.charAt(i) - 97]++;

        List<Integer> less = new ArrayList<>();
        List<Integer> more = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            if (freq[i] < origFreq[i]) less.add(i);
            else if (freq[i] > origFreq[i]) more.add(i);
        }

        int i = 0, j = 0, answer = 0;
        while (i < less.size() && j < more.size()) {
            int req = origFreq[less.get(i)] - freq[less.get(i)];
            int excess = freq[more.get(j)] - origFreq[more.get(j)];
            int adjust = Math.min(req, excess);

            answer += adjust;

            freq[less.get(i)] += adjust;
            freq[more.get(j)] -= adjust;
            if (adjust == req) i++;
            if (adjust == excess) j++;
        }

        while (i < less.size()) {
            answer += origFreq[less.get(i)] - freq[less.get(i)];
            i++;
        }

        while (j < more.size()) {
            answer += freq[more.get(j)] - origFreq[more.get(j)];
            j++;
        }

        return answer;
    }
}