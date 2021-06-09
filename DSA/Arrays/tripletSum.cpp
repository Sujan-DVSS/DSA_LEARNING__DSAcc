#include <bits/stdc++.h>
using namespace std;

int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,X;
  bool ans = false;
  cin >> n >> X;
  int arr[n];
  for(int i = 0 ; i < n ; i++) cin >> arr[i];
  cout << boolalpha;
  sort(arr, arr+n);
	for(int i = 0 ; i < n-2 ; i++){
		int low = i+1, high = n-1;
		// two pointer logic
		while(low < high){
			if(arr[i]+arr[low]+arr[high] == X){
				ans = true;
        break;
			}
			else if(arr[i]+arr[low]+arr[high] < X){
				low++;
			}
			else if(arr[i]+arr[low]+arr[high] > X){
				high--;
			}
		}
		
	}
	cout << ans;
  return 0;
}
