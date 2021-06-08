#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll findMinDiff(vector<ll> &vec, ll n, ll m){
 ll minDiff = INT_MAX;
  sort(vec.begin(), vec.end());
  for(int i = 0 ; i <= n-m ; i++){
    if(minDiff > (vec[i+m-1] - vec[i])){
     minDiff = vec[i+m-1] - vec[i]; 
    }
  }
  return minDiff;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m;
  cin >> n >> m;
  vector<ll> vec;
  ll x;
  for(auto i = 0 ; i < n ; i ++){
   cin >> x;
    vec.push_back(x);
  }
  cout << findMinDiff(vec,n,m) <<"\n";
 return 0; 
}
