int swapBits(int x, int p1, int p2, int n){
    for(int i = p1, j = 20; i <= (p1 + n - 1); i++, j++){
        if((x & (1 << i))){
            x ^= (1 << j);
        }
    }

    for(int i = p2, j = p1; i <= (p2 + n - 1); i++, j++){
        if((x & (1 << i))){
            x |= (1 << j);
        }else{
            if((x & (1 << j))){
                x ^= (1 << j);
            }
        }
    }

    for(int i = p2, j = 20; i <= (p2 + n - 1); i++, j++){
        if((x & (1 << j))){
            x |= (1 << i);
        }else{
            if((x & (1 << i))){
                x ^= (1 << i);
            }
        }
    }

    for(int i = 20; i <= (20 + n - 1); i++){
        if((x & (1 << i))){
            x ^= (1 << i);
        }
    }
    
    return x;
}