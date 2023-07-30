internal class Solution {
    fun peakIndexInMountainArray(arr: IntArray): Int {
        var low = 1
        var high = arr.size - 2
        while (low <= high) {
            val mid = (low + high) / 2
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid
            if (arr[mid] > arr[mid - 1]) low = mid + 1 else high = mid - 1
        }
        return -1
    }
}