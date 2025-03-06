#include <iostream>
#include <map>
#include <utility>
#define int long long
std::map<int, std::pair<int, int>> mp;
int32_t main(){
  int n, k, m;
  std::cin >> n >> k >> m;
  for(int i = 0; i < n; i++){
    int t;
    std::cin >> t;
    mp[m - t] = {t, i};
  }
  int result = 0;
  for(int i = 0; i < n; i++){
    int t;
    std::cin >> t;
    if(mp.find(t) != mp.end()){ // check if key exists
      if(std::abs(mp[t].second - i) >= k){
        result++;
      }
    }
  }
  std::cout << result << '\n';
}