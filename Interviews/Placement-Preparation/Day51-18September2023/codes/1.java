import java.util.PriorityQueue;

public class LC1337 {
    record Row(int soldiers, int index) implements Comparable<Row> {

        @Override
        public int compareTo(Row o) {
            return (o.soldiers() != this.soldiers() ? this.soldiers() - o.soldiers() : this.index() - o.index());
        }
    }

    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<Row> pq = new PriorityQueue<>();
        for (int i = 0; i < mat.length; i++) {
            int soldiers = 0;
            for (int j = 0; j < mat[i].length; j++) soldiers += mat[i][j] == 1 ? 1 : 0;
            pq.offer(new Row(soldiers, i));
        }

        int[] answer = new int[k];
        for (int i = 0; i < k; i++) {
            Row r = pq.poll();
            assert r != null;
            answer[i] = r.index();
        }

        return answer;
    }
}