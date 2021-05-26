
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ;i++) cin >> arr[i];
    
    // we can solve this problem using hashing but it would take O(nlogn) time and O(n) space;
    // we use moore's voting algorithm to find a num whose count is > n/2;
    // there's another optimal method for count  > n/3 instead of hashing. but if it greater than n/4 then use hashing
    
    int maj_idx{0},count{1};
    for(int i = 1 ; i < n ; i++){
     if( arr[maj_idx] == arr[i] ) count++;
     else count--;
        if(count == 0){
         maj_idx = i;
         count = 1;
        }
    }
    cout << arr[maj_idx] <<  " ";
 return 0;   
}
