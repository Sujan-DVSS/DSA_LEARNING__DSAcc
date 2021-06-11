#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target){
 sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    if(n < 4) return ans;
    for(int i = 0 ; i < n-3 ; i++){
     for(int j = i+1 ; j < n-2 ; j++){
      int low = j+1, high = n-1;
         int sum = target-nums[i]-nums[j];
         while(low < high){
          if(nums[low] + nums[high] == sum){
           vector<int> temp;
              temp.push_back(nums[i]);
              temp.push_back(nums[j]);
              temp.push_back(nums[low]);
              temp.push_back(nums[high]);
              res.push_back(temp);
              
              while(low < high and nums[low] == nums[low+1]) low++;
              while(low < high and nums[high] == nums[high-1]) high--;
              low++;
              high--;           
          }
             else if(nums[low] + nums[high] < sum) low++;
             else high--;
             
         }
         while(j < n-2 and nums[j] == nums[j+1]) j++;
             
     }
        while(i < n-3 and nums[i] == nums[i+1]) i++;
        
    }
    return res;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    vector<int>nums;
    cin >> n >> target;
    for(int i = 0 ; i < n ; i++){
     int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> res = fourSum(nums,target);
	
	for(auto i: res){
		cout << "[ "<<i[0] << "," << i[1] << "," << i[2] <<"," << i[3] << " ]" << " ";
	}
 return 0;   
}
