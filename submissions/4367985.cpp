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

#define ok "\n"
#define pi pair<int, int>
#define int long long

const int MN = 1000005, INF = 0x3f3f3f3f;
int n, q, arr[MN];
pi t[4 * MN]; // first is time, second is complete/incomplete

void build(int l, int r, int idx) {
    if (l == r) t[idx] = { arr[l], 1 };
    else {
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        t[idx] = { t[idx * 2].first + t[idx * 2 + 1].first, t[idx * 2].second + t[idx * 2 + 1].second};
    }
}

void upd(int l, int r, int cidx, int cval, int idx) {
    if (l == r) {
        t[idx].first += cval;
        if (t[idx].second == 1 && t[idx].first <= 0) {
            t[idx].second = 0;
        }
        else if (t[idx].first > 0) t[idx].second = 1;
    }
    else {
        int mid = (l + r) / 2;
        if (cidx <= mid) upd(l, mid, cidx, cval, idx * 2);
        else upd(mid + 1, r, cidx, cval, idx * 2 + 1);
        t[idx] = { t[idx * 2].first + t[idx * 2 + 1].first, t[idx * 2].second + t[idx * 2 + 1].second };
    }
}

int qry(int l, int r, int ql, int qr, int idx, int type) {
    if (type == 2) {
        if (r < ql || l > qr) return 0;
        else if (qr >= r && ql <= l) return t[idx].first;
        else {
            int mid = (l + r) / 2;
            int left = qry(l, mid, ql, min(qr, mid), idx * 2, 2);
            int right = qry(mid + 1, r, max(ql, mid + 1), qr, idx * 2 + 1, 2);
            return left + right;
        }
    }
    else {
        if (r < ql || l > qr) return 0;
        else if (qr >= r && ql <= l) return t[idx].second;
        else {
            int mid = (l + r) / 2;
            int left = qry(l, mid, ql, min(qr, mid), idx * 2, 3);
            int right = qry(mid + 1, r, max(ql, mid + 1), qr, idx * 2 + 1, 3);
            return left + right;
        }
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    n = readInt(1, 1e6); readSpace();
    q = readInt(1, 1e6); readNewLine();
    arr[1] = readInt(1, 1e6);
    for (int i = 2; i <= n; i++) {
        readSpace(); arr[i] = readInt(1, 1e6);
    }
    readNewLine();

    build(1, n, 1);

    while (q--) {
        int o = readInt(1, 3); readSpace();
        if (o == 1) {
            int i, x;
            i = readInt(1, n); readSpace(); x = readInt(1, 1e6); readNewLine();
            upd(1, n, i, -x, 1);
        }
        else {
            int l, r;
            l = readInt(1, n); readSpace(); r = readInt(l, n); readNewLine();
            std::cout << max(qry(1, n, l, r, 1, o), 0LL) << ok;
        }
    }

    return 0;
}