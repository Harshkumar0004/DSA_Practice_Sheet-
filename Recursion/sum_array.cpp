#include <iostream>
using namespace std;

int sumofarr(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


int sumarr(int arr[], int n) {
    if (n == 0) return 0;        
    return arr[n-1] + sumarr(arr, n-1); 
}


int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sumofarr(arr, n);
    return 0;
}