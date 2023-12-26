 void mergeSort(vector<int>& nums, int low, int high, int* ans) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, ans);
        mergeSort(nums, mid + 1, high, ans);
        merge(nums, low, mid, high);
    }
    int countPairs(vector<int>&nums, int low, int mid, int high) {
        int ptr1 = low;
        int ptr2 = mid + 1;
        int cnt = 0;
        int actual = 0;
        int i;

        while (ptr1 <= mid) {
            cnt = (ptr2 - (mid + 1));
          
            
            while (ptr2 <= high && (2*(long)nums[ptr2]< (nums[ptr1]))) {

                cnt++;

                ptr2++;
              
            }
            actual = actual + (cnt);
            ptr1++;
        }

        return actual;
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        int ptr1 = low;
        int ptr2 = mid + 1;
        int ptr3 = low;
        

        while (ptr1 <= mid && ptr2 <= high) {
            if (nums[ptr1] < nums[ptr2]) {
                dums[ptr3] = nums[ptr1];
                ptr3++;
                ptr1++;
            } else {
                dums[ptr3] = nums[ptr2];
                ptr3++;
                ptr2++;
            }
        }
        int i;
        for (i = ptr1; i <= mid; i++) {
            dums[ptr3] = nums[i];
            ptr3++;
        }
        for (i = ptr2; i <= high; i++) {
            dums[ptr3] = nums[i];
            ptr3++;
        }

        for (i = low; i <= high; i++) {
            nums[i] = dums[i];
        }

        return;
    }
