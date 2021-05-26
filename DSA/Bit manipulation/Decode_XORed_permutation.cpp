
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int encoded[n-1];
    for(int i = 0 ; i < n-1 ; i++) cin >> encoded[i];
    
    int tot_xor{}, tot_encoded_except_1{};
    for(int i = 1 ; i <= n ; i++) tot_xor ^= i;
    
    for(int i = 1; i < n-1 ; i+=2) tot_encode_except_1 ^= encoded[i];
    int first_val = tot_xor ^ tot_encoded_except_1, perm[n];
    perm[0] = first_val;
    for(int i = 1 ; i <  n ; i++) perm[i] = perm[i-1]^encoded[i-1];
    
    for(int i = 0 ; i <  n ; i++) cout << perm[i] << " ";
 return 0;   
}
