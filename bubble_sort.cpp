#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // array already sorted
    }
}

int main(){
    int arr[] = {64, 34,1,0,-1,91};
    bubblesort(arr, sizeof(arr)/sizeof(arr[0])); 

    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
//best case O(n)
//average & worst case O(n2)
