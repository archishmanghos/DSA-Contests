import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class LC17 {
    List<List<Character>> mp = new ArrayList<>();
    List<String> answer = new ArrayList<>();
    private void fnction(int idx, String digit, List<Character> li) {
        if (idx == digit.length()) {
            String s = li.stream().map(Object::toString).collect(Collectors.joining(""));
            if (!s.isEmpty()) answer.add(s);
            return;
        }

        for (var c : mp.get(((int)digit.charAt(idx)) - 50)) {
            li.add(c);
            fnction(idx + 1, digit, li);
            li.remove(li.size() - 1);
        }
    }
    public List<String> letterCombinations(String digits) {
        mp.add(new ArrayList<>(List.of('a', 'b', 'c')));
        mp.add(new ArrayList<>(List.of('d', 'e', 'f')));
        mp.add(new ArrayList<>(List.of('g', 'h', 'i')));
        mp.add(new ArrayList<>(List.of('j', 'k', 'l')));
        mp.add(new ArrayList<>(List.of('m', 'n', 'o')));
        mp.add(new ArrayList<>(List.of('p', 'q', 'r', 's')));
        mp.add(new ArrayList<>(List.of('t', 'u', 'v')));
        mp.add(new ArrayList<>(List.of('w', 'x', 'y', 'z')));

        fnction(0, digits, new ArrayList<>());
        return answer;
    }
}