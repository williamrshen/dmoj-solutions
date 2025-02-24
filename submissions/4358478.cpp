#include <bits/stdc++.h>
using namespace std;
template <class C> constexpr int sz(const C &c) { return int(c.size()); }
constexpr const char nl = '\n', sp = ' '; using uint = unsigned int;
using ll = long long; using ull = unsigned long long; using ld = long double;
#if __SIZEOF_INT128__
  using i128 = __int128_t; using ui128 = __uint128_t;
#endif

namespace Validator {
  std::regex nonWhitespaceChar("\\S");
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

  std::string readString(const std::regex &rgx) {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  std::string readString() {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    return ret;
  }

  char readChar(const std::regex &rgx = nonWhitespaceChar) {
    char ret = _getChar();
    assert(std::regex_match(std::string(1, ret), rgx));
    return ret;
  }

  std::string readLine(const std::regex &rgx) {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  std::string readLine() {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
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

int main() {
  int N = readInt(0, 1e5);
  readSpace();
  int A = readInt(0, 1e5);
  readSpace();
  int B = readInt(0, 1e5);
  readNewLine();
  int andrew = 0, tommy = 0;
  for (int i = 0; i < N; i++) {
    int x = readInt(0, 1e5);
    readSpace();
    int y = readInt(0, 1e5);
    readNewLine();
    andrew += 1 + (x >= A);
    tommy += 1 + (y >= B);
  }
//   readEOF();
  if (andrew < tommy) cout << "Andrew wins!" << nl;
  else if (andrew > tommy) cout << "Tommy wins!" << nl;
  else cout << "Tie!" << nl;
  return 0;
}