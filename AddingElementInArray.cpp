#include <iostream>
using namespace std;
int insert(int arr[],int n,int x,int cap,int pos){
    if(n==cap){
        return n;
    }
    int idx=pos-1;
    for(int i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
        arr[idx]=x;
        return n+1;       
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int n = 5;  
    int cap = 10;  
 
    n = insert(arr, n, 10, cap, 3);
 
    cout << "Array after insertion:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} 

