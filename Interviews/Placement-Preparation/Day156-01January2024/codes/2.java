import java.util.ArrayList;
import java.util.Collections;

public class LC455 {
    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a)
            l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++)
            a[i] = l.get(i);
    }

    public int findContentChildren(int[] g, int[] s) {
        sort(g);
        sort(s);

        int j = 0;
        for (int i = 0; i < s.length && j < g.length; i++) {
            if (g[j] <= s[i]) j++;
        }

        return j;
    }
}