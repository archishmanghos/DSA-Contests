int countSquare(int B){
    B = (B - 2 - (B % 2)) / 2;
    return (B > 0 ? B * (B + 1) / 2 : 0);
}