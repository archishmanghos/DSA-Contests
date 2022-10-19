class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0, cntSetBits = 0;
        for (int i = 0; i <= 30; i++) {
            if ((num2 >> i) & 1) {
                cntSetBits += 1;
            }
        }
        for (int i = 0; i <= 30; i++) {
            if ((num1 >> i) & 1) {
                ans |= (1 << i);
                cntSetBits -= 1;
            }
        }

        if (cntSetBits == 0) return ans;
        if (cntSetBits < 0) {
            for (int i = 0; i <= 30; i++) {
                if ((ans >> i) & 1) {
                    ans ^= (1 << i);
                    cntSetBits += 1;
                }
                if (!cntSetBits) return ans;
            }
        } else {
            for (int i = 0; i <= 30; i++) {
                if (!((ans >> i) & 1)) {
                    ans ^= (1 << i);
                    cntSetBits -= 1;
                }
                if (!cntSetBits) return ans;
            }
        }

        return -1;
    }
};