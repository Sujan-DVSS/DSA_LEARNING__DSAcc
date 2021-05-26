
#include <iostream>
using namespace std;

int main(){
    int left, right;
    cin >> left >> right;
    int count{};
    while(left != right){
        left = left >> 1;
        right = right >> 1;
        count++;
    }
    
    cout << (left << count); // or (right << count);
    
 return 0;   
}
