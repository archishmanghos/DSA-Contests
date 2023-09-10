public class LC338 {
    public int[] countBits(int n) {
        int[] answer = new int[n + 1];
        int one_bits = 0;
        answer[0] = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                one_bits = 1;
            } else {
                int k = i - 1;
                if (k % 2 == 0) one_bits++;
                else {
                    int deduct = 0;
                    while (k % 2 != 0) {
                        deduct++;
                        k >>= 1;
                    }

                    one_bits -= (deduct - 1);
                }
            }

            answer[i] = one_bits;
        }

        return answer;
    }
}