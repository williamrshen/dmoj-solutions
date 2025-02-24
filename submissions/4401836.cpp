#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int main (){
    cin.tie(0); cin.sync_with_stdio(0);
int n, q;
cin>>n>>q;
int r[n], psum[n];
for (int i=0; i<n; i++){
  cin>>r[i];
	}
	psum[0]=r[0];
	for (int i=1; i<n; i++){
		psum[i]=r[i]+psum[i-1];
	}
    for (int i=0; i<q; i++){
      int a, b;
        cin>>a>>b;
				int t=psum[n-1];
				if (a==1){
					cout<<t-psum[b-1]<<endl;
				}
				else {
				int range=psum[b-1]-psum[a-2];
          cout<<t-range<<endl;
					}
    }
	return 0;
}