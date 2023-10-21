package striver_sde_sheet.array1;

public class P3NP {
    private int[] reverse(int[] arr, int idx) {
        int i = idx, j = arr.length - 1;
        while (i < j) {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
            i++;
            j--;
        }

        return arr;
    }

    public void nextPermutation(int[] nums) {
        int breakIndex = -1, n = nums.length;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakIndex = i;
                break;
            }
        }

        if (breakIndex == -1) {
            nums = reverse(nums, 0);
            return;
        }

        int leastButGreater = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[breakIndex]) {
                leastButGreater = i;
                break;
            }
        }

        nums[breakIndex] = nums[breakIndex] + nums[leastButGreater];
        nums[leastButGreater] = nums[breakIndex] - nums[leastButGreater];
        nums[breakIndex] = nums[breakIndex] - nums[leastButGreater];
        nums = reverse(nums, breakIndex + 1);
    }
}