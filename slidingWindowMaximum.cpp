#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

void nextGreatest(vector<int> &arr, vector<int> &ans){
	stack<int> stk;
	for(int i=arr.size()-1; i>=0; i--){
		while(!stk.empty() && arr[i]>arr[stk.top()]){
			stk.pop();
		}
		if(stk.empty()){
			ans[i] = arr.size();
			stk.push(i);
		}
		else{
			ans[i] = stk.top();
			stk.push(i);
		}
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int k;
	cin >> k;
	vector<int> nextG(n);
	nextGreatest(arr, nextG);
	cout << "next greatest array\n";
	for(int e : nextG)
	    cout << e << " ";
	cout << endl;
	int j = 0;
	vector<int> ans;
	cout << "no problem until here\n";
	for(int i=0; i<=n-k; i++){
	    if(j<i)
	        j = i;
		while(nextG[j] < i+k){
			j = nextG[j];
		}
		ans.push_back(arr[j]);
	}
	for(int e: ans)
	    cout << e << " ";
    cout << endl;
	return 0;
}