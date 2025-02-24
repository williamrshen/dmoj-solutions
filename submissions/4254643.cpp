#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
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
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5 + 5;
int N, A, B, X[MM], Y[MM];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    N = readInt(0, 1e5); readSpace();
    A = readInt(0, 1e5); readSpace();
    B = readInt(0, 1e5); readNewLine();
    int a = 0, t = 0;
    for (int i = 1; i <= N; i++) {
        X[i] = readInt(0, 1e5); readSpace(); Y[i] = readInt(0, 1e5); readNewLine();
        a += 1 + X[i] > A;
        t += 1 + Y[i] > B;
    }
    if (a > t) cout << "Tommy wins!\n";
    else if (a == t) cout << "Tie!\n";
    else if (a < t) cout << "Andrew wins!\n";
}