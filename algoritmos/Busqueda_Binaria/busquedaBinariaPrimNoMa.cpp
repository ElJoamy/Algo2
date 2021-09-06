#include <bits/stdc++.h>
using namespace std;
int n;
int x;
int A[100010];

bool f(int number) { 
    return number>=x;
}

void binarySearch() {
    int ini = 0; 
    int fin = n-1;
    while(ini<fin) { 
        int mid = (ini + fin) / 2;
        if(f(A[mid])) {
            fin = mid;
        } else {
            ini = mid + 1 ; 
        }
    }

    if(f(A[ini])) {
        cout<<A[ini]<<endl;
    } else {
        cout<<"No hay"<<endl;
    }
}

int main() {
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>A[i];
    }
    cin>>x;
    binarySearch();
    return 0;
}
