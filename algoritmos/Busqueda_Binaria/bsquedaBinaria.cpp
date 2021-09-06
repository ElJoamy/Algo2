#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int left, int right, int x){
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (arr[mid] == x) { 
            return mid;
        }
        if (arr[mid] < x) { 
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void){
    int arr[] = {}; 
    int x = 0; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "El elemento no está presente en el arreglo"
    : cout << "El elemento está presente en el índice " << result<<endl;
    return 0;
}
