
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> res(n+1);
    res[0] = 0;
    for(int i = 1; i <= n ; i++){
     res[i]  = res[i >> 1] + i%2;   // or res[i] = res[i/2] + i%2;  // decode the logic. you will understand why
    }
    for(int i = 0 ; i <= n ; i++) cout << res[i] << " ";
    return 0;
}
