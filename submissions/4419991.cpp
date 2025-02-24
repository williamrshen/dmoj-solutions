#include <bits/stdc++.h>

using namespace std;

namespace Validator {
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

    char readChar(const std::regex &rgx) {
        char ret = _getChar();
        assert(std::regex_match(std::string(1, ret), rgx));
        return ret;
    }

    char readChar() {
        return _getChar();
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

struct FenwickTree {

    vector<int> bit;

    FenwickTree(int n) : bit(n + 1, 0) {}

    int parent(int n) {
        return n - (n & (-n));
    }

    int next(int n) {
        return n + (n & (-n));
    }

    int getNum(int n) {
        return getSum(n) - getSum(n - 1);
    }

    int getSum(int n) {
        int sum = 0;
        n++;
        while (n > 0) {
            sum += bit[n];
            n = parent(n);
        }
        return sum;
    }

    int getSum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }

    void update(int n, int x) {
        n++;
        while (n < bit.size()) {
            bit[n] += x;
            n = next(n);
        }
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n = readInt(1, 1000000);
    readSpace();
    int q = readInt(1, 1000000);
    readNewLine();
    FenwickTree bit(n), unfinished(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            readSpace();
        }
        int t = readInt(1, 1000);
        bit.update(i, t);
        unfinished.update(i, 1);
    }
    readNewLine();
    for (int i = 0; i < q; i++) {
        int query = readInt(1, 3);
        readSpace();
        if (query == 1) {
            int idx = readInt(1, n) - 1;
            readSpace();
            int minutes = readInt(1, bit.getNum(idx));
            bit.update(idx, -minutes);
        } else if (query == 2) {
            int l = readInt(1, n) - 1;
            readSpace();
            int r = readInt(1, n) - 1;
            assert(r >= l);
            printf("%d\n", bit.getSum(l, r));
        } else {
            int l = readInt(1, n) - 1;
            readSpace();
            int r = readInt(1, n) - 1;
            assert(r >= l);
            printf("%d\n", unfinished.getSum(l, r));
        }
        readNewLine();
    }
    readEOF();
    return 0;
}