#include <bits/stdc++.h>
using namespace std;

long merge(int arr[], int temp[], int low, int mid, int high){
 int i = low, j = mid, k = low;
  long inv_count{};
  while(i < mid and j <= high){
   if(arr[i] <= arr[j]){
    temp[k++] = arr[i++]; 
   }else{
    temp[k++] = arr[j++];
     inv_count += mid-i;
   }
  }
  
  while(i < mid) temp[k++] = arr[i++];
  while(j <= high) temp[k++] = arr[j++];
  for(int i = low; i <= high ; i++) arr[i] = temp[i];
  return inv_count;
  
}

long mergeSort(int arr[], int temp[], int low, int high){
 long count{};
  if(low < high){
    
   int mid = low+(high-low)/2;
    count += mergeSort(arr,temp,low,mid);
    count += mergeSort(arr,temp,mid+1,high);
    count += merge(arr,temp,low,mid+1,high);
    
    
  }
  return count;
  
}

long countInversion(int arr[], int low, int high){
 int temp[high+1];
  return mergeSort(arr,temp,low,high);
}

int main(){
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i < n ; i++) cin >> arr[i];
  cout << countInversion(arr,0,n-1) << "\n";
    return 0;
  
}
