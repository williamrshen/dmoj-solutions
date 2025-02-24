#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
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
const int MM = 1e5 + 5;
int N, T[MM], IN[MM], DIST[MM];
vector<int> radj[MM];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    N = readInt(1, 1e5); readNewLine();
    for (int i = 1; i <= N; i++) {
        T[i] = readInt(1, 1e4); readSpace();
        int sz = readInt(0, N - 1);
        if (sz == 0) readNewLine();
        else readSpace();
        for (int j = 1; j <= sz; j++) {
            int u = readInt(1, N);
            if (j == sz) readNewLine();
            else readSpace();
            radj[u].pb(i); IN[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!IN[i]) DIST[i] = T[i], q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : radj[u]) {
            DIST[v] = max(DIST[v], DIST[u] + T[v]);
            if (--IN[v] == 0) q.push(v);
        }
    }
    ll res = 0;
    for (int i = 1; i <= N; i++) if (!IN[i]) res = max((ll)DIST[i], res);
    cout << res << "\n";
}