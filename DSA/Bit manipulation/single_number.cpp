
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    //let's find the single number out of all 2 times repeated
    // XOR ... a^a = 0, a^0 = a; so two a^b^c^c^a = b. This is XOR power.Very important insight
    
    int res{}; // or res = 0;
    for(int i = 0 ; i < n ; i++){
     res = res ^ arr[i];   
    }
    
    cout << res << " ";
 return 0;   
}
