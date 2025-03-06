#include <bits/stdc++.h>
using namespace std;
template <class C> constexpr int sz(const C &c) { return int(c.size()); }
constexpr const char nl = '\n', sp = ' '; using uint = unsigned int;
using ll = long long; using ull = unsigned long long; using ld = long double;
#if __SIZEOF_INT128__
  using i128 = __int128_t; using ui128 = __uint128_t;
#endif

namespace Validator {
  std::regex nonWhitespaceToken("\\S+"), nonWhitespaceChar("\\S"), anyLine(".+");
  bool _hasLast = false;
  char _last;

  char _peekChar() {
    _last = _hasLast ? _last : getchar();
    _hasLast = true;
    return _last;
  }

  char _getChar() {
    char ret = _peekChar();
    _hasLast = false;
    return ret;
  }

  long long readInt(long long minValid = std::numeric_limits<long long>::min(), long long maxValid = std::numeric_limits<long long>::max()) {
    std::string token = "";
    while (isdigit(_peekChar()) || _peekChar() == '-') token.push_back(_getChar());
    long long ret = std::stoll(token);
    assert(minValid <= ret && ret <= maxValid);
    return ret;
  }

  long double readFloat(long double minValid = std::numeric_limits<long double>::lowest(), long double maxValid = std::numeric_limits<long double>::max()) {
    std::string token = "";
    while (isdigit(_peekChar()) || _peekChar() == '-' || _peekChar() == '.') token.push_back(_getChar());
    long double ret = std::stold(token);
    assert(minValid <= ret && ret <= maxValid);
    return ret;
  }

  std::string readString(const std::regex &rgx = nonWhitespaceToken) {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  char readChar(const std::regex &rgx = nonWhitespaceChar) {
    char ret = _getChar();
    assert(std::regex_match(std::string(1, ret), rgx));
    return ret;
  }

  std::string readLine(const std::regex &rgx = anyLine) {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  void readSpace() {
    assert(_getChar() == ' ');
  }

  void readNewLine() {
    assert(_getChar() == '\n');
  }

  void readEOF() {
    assert(_getChar() == std::char_traits<char>::eof());
  }
}

using namespace Validator;

vector<int> s;

int main() {
    int n = readInt(1, 1e6); readNewLine();
    int x = readInt(0, 9);
    s.push_back(x);
    for (int i = 1; i < n * 2; i ++) {
        readSpace();
        x = readInt(0, 9);
        s.push_back(x);
    }
    readNewLine();
    sort(s.begin(), s.end());
    
    string out = "";
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < s[n - 1 - i]; j ++) {
            out += to_string(s[n + i]);
        }
    }
    
    if (out == "") cout << 0 << "\n";
    else cout << out << "\n";
    
    readEOF();
    return 0;
}