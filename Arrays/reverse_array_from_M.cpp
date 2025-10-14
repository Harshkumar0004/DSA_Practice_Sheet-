void swapelement(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(vector<int> &arr, int m) {
    // set left pointer to the element just after index m
    int left = m + 1;
    
    // set right pointer to the last element of the array
    int right = arr.size() - 1;

    // continue swapping until both pointers meet in the middle
    while (left < right) {
        // swap the elements at left and right positions
        swapelement(arr[left], arr[right]);

        // move pointers closer towards the center
        left++;
        right--;
    }     	
}