class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 1, high = arr.length - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            if (arr[mid] > arr[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
}