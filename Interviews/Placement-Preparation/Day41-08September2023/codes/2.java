public class LC11 {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1, answer = 0;
        while (i < j) {
            answer = Math.max(answer, Math.min(height[i], height[j]) * (j - i));
            if (height[i] <= height[j]) i++;
            else j--;
        }

        return answer;
    }
}