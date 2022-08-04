int mirrorReflection(int p, int q) {
    while (p % 2 == 0 and q % 2 == 0) {
        p >>= 1;
        q >>= 1;
    }

    return (p % 2 == 0 ? 2 : q % 2 == 0 ? 0 : 1);
}