#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<int> p;
int l(int u){
	if(p[u]==u){
		return u;
	}
	p[u]=l(p[u]);
	return p[u];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i=0; i<=n+10; ++i){
		p.push_back(i);
	}
	char c;
	int x, y;
	while(q--){
		cin >> c >> x >> y;
		if(c=='A'){
			p[l(y)]=l(x);
		} else{
			if(l(x)==l(y)){
				cout << "Y\n";
			} else{
				cout << "N\n";
			}
		}
	}
}