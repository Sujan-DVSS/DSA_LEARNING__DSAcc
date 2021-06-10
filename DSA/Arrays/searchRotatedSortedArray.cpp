#include<bits/stdc++.h>
using namespace std;

int searchRA(vector<int> &arr, int target){
	int low = 0,high = arr.size()-1;
	while(low <= high){
		int mid = low+(high-low)/2;
		if(arr[mid] == target) return mid;
		else if(arr[low] <= arr[mid]){
			if(target >= arr[low] and target < arr[mid])
			   high = mid-1;
		    else
		       low = mid+1;
		}else{
			if(target > arr[mid]  and target <= arr[high])
			   low = mid+1;
		    else
		       high = mid-1;
		}
	}
	return -1;
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,target;
	cin >> n >> target;
	vector<int> arr;
	for(int i = 0 ;i < n ;i++){
		int x;
		cin >>x;
		arr.push_back(x);
	}
	cout << searchRA(arr,target);
	
	return 0;
	
}
