int convertTime(string current, string correct){
    string hour1 = current.substr(0, 2);
    string min1 = current.substr(3);
    string hour2 = correct.substr(0, 2);
    string min2 = correct.substr(3);
    
    int time1 = 0, j = 1;
    for(int i = 1; i >= 0; i--){
        time1 += (hour1[i] - '0') * j;
        j *= 10;
    }
    time1 *= 60, j = 1;
    for(int i = 1; i >= 0; i--){
        time1 += (min1[i] - '0') * j;
        j *= 10;
    }
    
    int time2 = 0;
    j = 1;
    for(int i = 1; i >= 0; i--){
        time2 += (hour2[i] - '0') * j;
        j *= 10;
    }
    time2 *= 60, j = 1;
    for(int i = 1; i >= 0; i--){
        time2 += (min2[i] - '0') * j;
        j *= 10;
    }
    
    
    int arr[4] = {60, 15, 5, 1}, ans = 0, time;
    if(time1 <= time2){
        time = (time2 - time1);
    }else{
        time = (1439 - time1) + time2;
    }

    for(int i = 0; i < 4; i++){
        ans += time / arr[i];
        time %= arr[i];
    }
    return ans;
}