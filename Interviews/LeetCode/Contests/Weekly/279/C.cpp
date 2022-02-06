string bitset1, bitset2;
int setBit1, setBit2, total;
bool inverse = false;

Bitset(int size) {
    bitset1 = bitset2 = "";
    for (int i = 1; i <= size; i++) {
        bitset1 += '0';
        bitset2 += '1';
    }

    setBit1 = 0;
    total = setBit2 = size;
}

void fix(int idx) {
    if (inverse) {
        if (bitset1[idx] == '1') {
            bitset1[idx] = '0';
            setBit1 -= 1;
        }
        if (bitset2[idx] == '0') {
            bitset2[idx] = '1';
            setBit2 += 1;
        }
    } else {
        if (bitset1[idx] == '0') {
            bitset1[idx] = '1';
            setBit1 += 1;
        }
        if (bitset2[idx] == '1') {
            bitset2[idx] = '0';
            setBit2 -= 1;
        }
    }
}

void unfix(int idx) {
    if (inverse) {
        if (bitset1[idx] == '0') {
            bitset1[idx] = '1';
            setBit1 += 1;
        }
        if (bitset2[idx] == '1') {
            bitset2[idx] = '0';
            setBit2 -= 1;
        }
    } else {
        if (bitset1[idx] == '1') {
            bitset1[idx] = '0';
            setBit1 -= 1;
        }
        if (bitset2[idx] == '0') {
            bitset2[idx] = '1';
            setBit2 += 1;
        }
    }
}

void flip() {
    inverse = !inverse;
}

bool all() {
    if (inverse) {
        return setBit2 == total;
    } else {
        return setBit1 == total;
    }
}

bool one() {
    if (inverse) {
        return setBit2 > 0;
    } else {
        return setBit1 > 0;
    }
}

int count() {
    if (inverse) {
        return setBit2;
    } else {
        return setBit1;
    }
}

string toString() {
    if (inverse) {
        return bitset2;
    } else {
        return bitset1;
    }
}