void sort012(int a[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low += 1, mid += 1;
        } else if (a[mid] == 1) {
            mid += 1;
        } else {
            swap(a[mid], a[high]);
            high -= 1;
        }
    }
}