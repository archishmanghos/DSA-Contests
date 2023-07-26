class Solution {
    fun f(mid: Int, dist: IntArray, hour: Double): Boolean {
        var totalTime = 0.0
        for (i in 0 until dist.size - 1) {
            totalTime += ((dist[i] + mid - 1) / mid).toDouble()
        }
        totalTime += dist[dist.size - 1].toDouble() / mid
        return totalTime <= hour
    }

    fun minSpeedOnTime(dist: IntArray, hour: Double): Int {
        var answer = -1
        var low = 1
        var high = 10000000
        while (low <= high) {
            val mid = (low + high) / 2
            if (f(mid, dist, hour)) {
                answer = mid
                high = mid - 1
            } else {
                low = mid + 1
            }
        }
        return answer
    }
}