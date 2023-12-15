import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC1436 {
    static class MutableInt {
        int value = 0;
        public void increment() { ++value; }
        public void decrement() { --value; }
        public int get() { return value; }
    }

    public String destCity(List<List<String>> paths) {
        Map<String, MutableInt> mp = new HashMap<>();
        for (var path : paths) {
            String u = path.get(0), v = path.get(1);

            if (mp.get(u) == null) mp.put(u, new MutableInt());
            mp.get(u).increment();

            if (mp.get(v) == null) mp.put(v, new MutableInt());
            mp.get(v).decrement();
        }

        for (String key : mp.keySet()) { if (mp.get(key).get() == -1) return key; }

        return "-1";
    }
}