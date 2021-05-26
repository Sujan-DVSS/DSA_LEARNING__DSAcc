
#include <iostream>
using namespace std;

int main(){
    int n,f{};
    cin >> n;
    if( n < 2) cout << "false";
    for(int i = 2 ; i*i <= n ; i++){
     if(n % i == 0)  {
         f = 1;
         cout << "false";
         break;
    }
    }
    if( !f) cout << "true";
    
 return 0;   
}
