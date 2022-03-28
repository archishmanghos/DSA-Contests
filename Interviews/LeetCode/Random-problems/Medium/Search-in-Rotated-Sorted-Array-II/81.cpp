bool search(vector<int> &nums, int target){
    int low1 = 0, high1 = -1, low2 = nums.size(), high2 = nums.size() - 1;
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i + 1]){
            high1 = i;
            low2 = i + 1;
            break;
        }
    }
    
    if(high1 == -1){
        high1 = nums.size() - 1;
        while(low1 <= high1){
            int mid = low1 + (high1 - low1) / 2;
            if(nums[mid] == target){
                return true;
            }

            if(nums[mid] < target){
                low1 = mid + 1;
            }else{
                high1 = mid - 1;
            }
        }
        return false;
    }

    while(low1 <= high1){
        int mid = low1 + (high1 - low1) / 2;
        if(nums[mid] == target){
            return true;
        }
        
        if(nums[mid] < target){
            low1 = mid + 1;
        }else{
            high1 = mid - 1;
        }
    }
    
    while(low2 <= high2){
        int mid = low2 + (high2 - low2) / 2;
        if(nums[mid] == target){
            return true;
        }
        
        if(nums[mid] < target){
            low2 = mid + 1;
        }else{
            high2 = mid - 1;
        }
    }
    
    return false;
}