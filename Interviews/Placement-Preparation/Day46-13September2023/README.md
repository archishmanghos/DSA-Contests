<h2>135. Candy</h2>

[Link to Problem](https://leetcode.com/problems/candy)

<details><summary>Codes</summary>

```java
import java.util.PriorityQueue;

public class LC135 {
    record rating(int actualRating, int index) implements Comparable<rating> {
        @Override
        public int compareTo(rating o) {
            return (this.actualRating != o.actualRating ? this.actualRating - o.actualRating : this.index - o.index);
        }
    }

    public int candy(int[] ratings) {
        PriorityQueue<rating> pq = new PriorityQueue<>();
        for (int i = 0; i < ratings.length; i++) {
            pq.offer(new rating(ratings[i], i));
        }

        int[] answer = new int[ratings.length];
        while (!pq.isEmpty()) {
            rating r = pq.poll();
            int actualRating = r.actualRating();
            int index = r.index();

            int leftRating = 1, rightRating = 1;
            if (index - 1 >= 0 && answer[index - 1] > 0 && ratings[index - 1] < actualRating)
                leftRating = answer[index - 1] + 1;
            if (index + 1 < ratings.length && answer[index + 1] > 0 && ratings[index + 1] < actualRating)
                rightRating = answer[index + 1] + 1;

            answer[index] = Math.max(leftRating, rightRating);
        }
        int totalCandies = 0;
        for (int i : answer) totalCandies += i;
        return totalCandies;
    }
}
```

</details>
