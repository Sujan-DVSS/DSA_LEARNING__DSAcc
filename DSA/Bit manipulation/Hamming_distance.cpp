
#include <iostream>
using namespace std;

int main(){
 int n,m;
    cin >> n;
    cin >> m;
int x = n ^ m, count{};
    while(x){
     x = x & (x-1);
        count++;
    }
    cout << count << " ";
    return 0;
 
}
