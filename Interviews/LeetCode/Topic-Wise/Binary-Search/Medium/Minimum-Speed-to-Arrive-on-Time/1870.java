class Solution {
    public boolean f(int mid, int[] dist, double hour) {
        double totalTime = 0.0;
        for (int i = 0; i < dist.length - 1; i++) {
            totalTime += (dist[i] + mid - 1) / mid;
        }
        totalTime += (double) dist[dist.length - 1] / mid;
        return (totalTime <= hour);
    }

    public int minSpeedOnTime(int[] dist, double hour) {
        int answer = -1, low = 1, high = 10000000;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (f(mid, dist, hour)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
}