#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& dsuf, int x){
	return dsuf[x] == -1 ? x: dsuf[x] = find(dsuf,dsuf[x]);
}

void unionS(vector<int>& dsuf, int x, int z){
    int parentX = find(dsuf,x);
	int parentZ = find(dsuf,z);
	
	if(parentX == parentZ) return;
	dsuf[parentX] = parentZ; 

}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> dsuf(n);
	for(int i = 0;i < n ; i++) dsuf[i] = -1;	
	
	int q;
	cin >> q;
	for(int i = 0 ; i < q; i++){
	    string query;
		cin >> query;
		if(query == "UNION"){
		    int x,z;
			cin >> x >> z;
			unionS(dsuf,x,z);
		}
		else{
		    int x;
			cin >> x;
			int absParent = find(dsuf,x);
			cout << absParent << " ";
		}
	}
	return 0;
}
