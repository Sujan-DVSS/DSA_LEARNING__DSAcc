
#include <iostream>
using namespace std;

int main(){
  int X,Y;
  cin >> X >> Y;
  long long ans = 1;
  while(Y){
    
    if(Y%2 == 1){
     ans *=  X;
      
    }
    X = X*X;
    Y/=2;
    
  }
  cout << ans << " ";
 return 0; 
}
