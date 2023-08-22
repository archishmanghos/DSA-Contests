class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder answer = new StringBuilder();

        while (columnNumber > 0) {
            int characterNow = columnNumber % 26;
            columnNumber /= 26;
            if (characterNow == 0) {
                characterNow = 26;
                --columnNumber;
            }
            answer.append((char) ((characterNow - 1) + 65));
        }

        answer.reverse();
        return answer.toString();
    }
}