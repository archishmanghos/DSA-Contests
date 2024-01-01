import java.util.*;
import java.util.function.Function;

public class LC2933 {
    public List<String> findHighAccessEmployees(List<List<String>> access_times) {
        Map<String, List<Integer>> mp = new HashMap<>();
        Function<String, Integer> getTime = (String t) -> Integer.parseInt(t.substring(0, 2)) * 60 + Integer.parseInt(t.substring(2));

        for (var x : access_times) {
            String emp = x.get(0);
            int time = getTime.apply(x.get(1));
            mp.putIfAbsent(emp, new ArrayList<>());
            mp.get(emp).add(time);
        }

        List<String> answer = new ArrayList<>();
        for (String key : mp.keySet()) {
            Collections.sort(mp.get(key));
            if (mp.get(key).size() >= 3) {
                for (int i = 0; i + 2 < mp.get(key).size(); i++) {
                    if (mp.get(key).get(i + 2) - mp.get(key).get(i) < 60) {
                        answer.add(key);
                        break;
                    }
                }
            }
        }

        return answer;
    }
}