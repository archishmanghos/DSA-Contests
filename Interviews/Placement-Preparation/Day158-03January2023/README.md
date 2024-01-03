<h2>2125. Number of Laser Beams in a Bank</h2>

[Link to Problem](https://leetcode.com/problems/number-of-laser-beams-in-a-bank)

<details><summary>Code</summary>

```java
public class LC2125 {
    public int numberOfBeams(String[] bank) {
        int answer = 0, preLaserCount = 0;
        for (String s : bank) {
            int laserCount = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '1') laserCount++;
            }
            answer += preLaserCount * laserCount;
            if (laserCount > 0) preLaserCount = laserCount;
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>216. Combination Sum III</h2>

[Link to Problem](https://leetcode.com/problems/combination-sum-iii)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.List;

public class LC216 {
    List<List<Integer>> answer = new ArrayList<>();

    private void fnction(int num, int sumRemaining, int k, List<Integer> l) {
        if (sumRemaining == 0) {
            if (k == 0) answer.add(new ArrayList<>(l));
            return;
        }
        if (k == 0 || num > 9) return;

        if (num <= sumRemaining) {
            l.add(num);
            fnction(num + 1, sumRemaining - num, k - 1, l);
            l.remove(l.size() - 1);
        }
        fnction(num + 1, sumRemaining, k, l);
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> l = new ArrayList<>();
        fnction(1, n, k, l);
        return answer;
    }
}
```

</details>

<br>
<br>