
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void sieve(vector<bool> &prime,int n){
prime[0] = false;
	prime[1] = false;
	for(int i = 2; i <= sqrt(n) ;i++){
		if(prime[i] ==true){
		for(int j = i*i ; j <= n ; j += i){ prime[j] = false;}
		}
	}
	
}

int main(){
 int n;
cin >> n;
	vector <bool> prime(n+1,true);
	sieve(prime,n);
	cout << boolalpha;
	for(int i = 1 ; i <= n ; i++) cout << prime[i];
 
    
}
