// Naive: try out all subsets and check. Time - O(N.2^N) 
// Optimized approach: use meet in the middle algo
/*This problem can be solved using meet in the middle algorithm*/
/*
Approach:
step 1: divide the array into 2 equal parts
step 2: find the sum of all subsets for the divided 2 arrays separetly and store it in sub1 and sub2 arrays(using bit manip technique)
step 3: sort the sub2 array(Second array) to perform binary search
step 4: Now first of all, find a new target for every element of sub1(target = goal-sub1[i]). So as to remove a sum in the first half
step 5: for every new target find a nearest sum in the sub2 using binary search and find the diff with it(sub2[mid]) to get min_diff
step 6: perform binary search and find the mininum
Total time : O(2^n/2 (sum of nums1) + 2^n/2 (sum of num2) + 2^(n/2)(log2 2^(n/2)) == (n/2)*2^(n/2)  (for sorting 2^(n/2) elements)
+ 2^(n/2)log2 (2^n/2) == (n/2)*2^(n/2) (for performing binary search on 2^(n/2) elements for 2^(n/2)) => O(n*(2^(n/2))
so, O(n*(2^(n/2)) < O(N.2^N)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> findSums(vector<int>& arr){
  int n = arr.size(),c = 0,sum;
 vector<int> res((1<<n),0); 
  for(int i = 0 ;i < (1<< n); i++){
    sum = 0;
    for(int j = 0; j < n ; j++){
     if(i & (1 << j)){
      sum += arr[j]; 
     }
    }
    res[c++] = sum;
  }
  return res;
}
int minAbsDifference(vector<int>& nums, int goal){
 int n = nums.size();
  vector<int> nums1, nums2;
  for(int i = 0; i < n/2; i++) nums1.push_back(nums[i]);
  for(int i = n/2; i < n ; i++) nums2.push_back(nums[i]);
  vector<int> sub1 = findSums(nums1), sub2 = findSums(nums2);
  
  sort(sub2.begin(),sub2.end());
  int min_diff = INT_MAX;
  for(int i = 0; i < sub1.size() ; i++){
   int target = goal-sub1[i];
    int low = 0, high = sub2.size()-1;
    while(low <= high){
     int mid = low + (high-low)/2;
      min_diff = min(min_diff, abs(target-sub2[mid]));
      if(sub2[mid] == target){
       break; 
      }else if(target < sub2[mid]){
       high = mid-1;
      }else{
       low = mid+1; 
      }
    }
  }
  return min_diff;
}

int main(){
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, goal;
  vector<int> nums;
  cin >> n >>  goal;
  for(int i = 0; i < n ; i++){
   int x;
    cin >> x;
    nums.push_back(x);
  }
  cout << minAbsDifference(nums,goal) << "\n";
  return 0; 
}
