#include<bits/stdc++.h>
using namespace std;

void convertToWave(int *arr, int n){
        
        // Your code here
        int i = 0;
        int j = i+1;
        while(i < n-1 and j <= n-1){
            swap(arr[i],arr[j]);
            i += 2;
            j = i+1;
        }
        
    }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n ; i++) cin >> arr[i];
	convertToWave(arr,n);
    for(int i = 0; i < n ; i++) cout << arr[i] <<" ";
	
	return 0;
}
