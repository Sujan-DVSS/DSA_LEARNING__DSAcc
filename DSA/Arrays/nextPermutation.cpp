#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums){
 int n = nums.size();
 // if the size of the nums is 1 then there is chance of permutation
 if(n == 1) return;
 // find the peak element of the last ascending order of the nums for finding the next permutation
 int peakEleIndx = -1 ,i = 1;
  while(i < n-1){
    if(nums[i+1] > nums[i]){
      peakEleIndx = i+1;  
    }
    i++;
  }
  // if there is no peak element that means peakEleIndx = -1 then it means complete nums is in desc order 
  // So, the reverse of the nums will the next permutation of the nums
  //Find reverse
  if(peakEleIndx == -1){
  for(int i = 0 ; i < n/2 ; i++)
  {
   swap(nums[i], nums[n-1-i]); 
  }
        return;
       }
  // Find an element which is just greater than nums[peakEleIndx-1] and less than nums[peakEleIndx] in the range(prEleIndx,n)
        int justMax = peakEleIndx;
        for(int i = peakEleIndx ; i < n ; i ++){
          if(nums[i] > nums[peakEleIndx-1] and nums[i] < nums[justMax]){
           justMax = i; 
          }
          
        }
  //Now, swap nums[preEleIndx-1] with nums[justMax]
        swap(nums[peakEleIndx-1], nums[justMax]);
   // Last step: Reverse or Sort the nums from preEleIndx to n
        sort(nums.begin()+peakEleIndx, nums.end());
    // reverse(nums.begin()+preEleIndx, nums.end());
}

int main(){
  int n;
  cin >> n;
  vector<int> nums;
  for(int i = 0 ; i < n ; i++){
   int x;
    cin >> x;
    nums.push_back(x);
  }
  
  nextPermutation(nums);
  
  for(int i: nums) cout << i << " ";
  
 return 0; 
}
