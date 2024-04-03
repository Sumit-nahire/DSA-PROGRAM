#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n) {
    int o[n];
    int c[10] = {0};
    
    for(int i=0; i<n; i++) {
        c[arr[i]]++;
    }

    for(int i=1; i<10; i++) {
        c[i] += c[i-1];
    }

    for(int i=n-1; i>=0; i--) {
        o[--c[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++) {
        arr[i] = o[i];
    }
}

int main() {
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    countSort(arr, n);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}