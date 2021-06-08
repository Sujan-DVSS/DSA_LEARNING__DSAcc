#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
 int minprice = INT_MAX;
  int maxprofit = 0;
  for(int i = 0 ; i < prices.size() ; i++){
   if(minprice > prices[i]){
    minprice = prices[i]; 
   }else if(maxprofit < prices[i]-minprice){
    maxprofit = prices[i] - minprice; 
   }
  }
  return maxprofit;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,x;
  cin >> n;
  vector<int> prices;
  for(int i = 0 ; i < n ; i++){
   cin >> x;
    prices.push_back(x);
  }
  cout << maxProfit(prices) << "\n";
 return 0; 
}
