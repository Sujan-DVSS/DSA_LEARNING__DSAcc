
#include <iostream>
using namespace std;

int main(){
 int n;
  cin >> n;
  int arr[n];
  for(int i = 0 ; i < n ; i++) cin >> arr[i];
 
  // There is an intuitive method in which arr is sorted and starct checking from i = 1. check if arr[i-1] is equal to arr[i]. we don't have check arr[i+1] as if one condition is
  // satisfied, then for sure there will be another. Now whenver the condition fails then return arr[i]. This logic has 2 boundary cases. 1. [1 2 2 2 4 4 4] return arr[0] directly
  //2. [2 2 2 3 3 3 5], return arr[n-1] directly as the above logic fails for these conditions.
  
   
  //This is a non-intuitive method. So practice more.
  
  int ones{},twos{};
  for(int i = 0 ; i < n ; i++){
    ones = (arr[i]^ones)& ~twos;
    twos = (arr[i]^twos)& ~ones;
    
  }
  
  cout << ones << " " ;  
  return 0;
}
