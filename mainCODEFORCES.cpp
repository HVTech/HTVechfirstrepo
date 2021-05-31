#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;
#define endl "\n"
#define lli long long int 
#define ll long long 
#define v(x) vector<x>
#define arr(x,size,A) x A[size]
#define x first
#define y second
ll to_longlong(string a){
	long long n = 0;
	for(int i = 0;i<a.size();i++){
		n += (int)(a[i] - '0');
		n*=10;
	}
	n/=10;
	return n;
}
string add(string a,string b){
	while(a.size() < b.size()) a = '0' + a;
	while(b.size() < a.size()) b = '0' + b;
	int br = 0;
	string res;
	for(int i = a.size()-1;i>=0;i--){
		int ar = (int)(a[i] - '0') + (int)(b[i] - '0') + br;
		br = ar/10;
		ar%=10;
		res =(char)(ar + '0') + res;
	}
	if(br > 0) res = '1' + res;
	return res;
}
string mul(string a,string b){
	v(int) cnt(a.size()  + b.size(),0);
	int index = 0;
	string res;
	for(int i = 0;i<a.size();i++){
		index = i + 1;
		for(int j = 0;j<b.size();j++){
			cnt[index] += (int)(a[i] - '0') * (int)(b[j] -'0');
			index++;
		}
	}
	for(int i = index-1;i>0;i--){
		cnt[i-1] += cnt[i]/10;
		cnt[i]%=10;
		res = (char)(cnt[i] + '0') + res;
	}
	if(cnt[0] > 0) res = (char)(cnt[0] + '0') + res;
	while(res[0] == '0' && res.size() > 1) res.erase(0,1);
	return res;
}
int check(string s,string res){ // 0 equal , -1 less than,1 more than
	if(s == res) return 0;
	if(s.size() < res.size()) return -1;
	if(s.size() > res.size()) return 1;
	int i = 0;
	while(i<s.size()){
		if(s[i] > res[i]) return 1;
		else if(s[i] < res[i]) return -1;
		i++;
	}
}
string sqrt(string a,string turn){
	lli l = 0,r = 1e15;
	while(l < r){
		lli mid = (l + r) / 2;
		string res = mul(to_string(mid),to_string(mid));
		//cout << mid << " " << res <<  endl;
		//cout << "left: "<<l << " right: "<<r << endl;
		if(check(res,a) == 0){
			l = mid;
			break;
		}else if(check(res,a) == 1){
			r = mid - 1;
		}else l = mid + 1;
		
	}
	if(turn == "first"){
		string res = mul(to_string(l),to_string(l));
		if(check(res,a) == -1) l++;
	}else{	
		string res = mul(to_string(l),to_string(l));	
		if(check(res,a) == 1) l--;
	}
	return to_string(l);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
