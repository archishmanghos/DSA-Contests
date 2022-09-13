int calculateBytes(int n) {
    int bytes = 0;
    for (int i = 7; i >= 0; i--) {
        if ((n >> i) & 1) {
            bytes += 1;
        } else {
            if (bytes == 1) return -1;
            if (bytes <= 4) return (bytes == 0 ? 1 : bytes);
            return -1;
        }
    }

    return -1;
}

bool continuation(int n) {
    return (((n >> 7) & 1) and !((n >> 6) & 1));
}

bool validUtf8(vector<int>& data) {
    int i = 0, n = data.size();
    while (i < n) {
        int bytes = calculateBytes(data[i]);
        if (bytes == -1) return false;
        i += 1;

        if (bytes > 1) {
            bytes -= 1;
            while (i < n and bytes--) {
                if (!continuation(data[i++])) return false;
            }

            if (bytes > 0) return false;
        }
    }

    return true;
}