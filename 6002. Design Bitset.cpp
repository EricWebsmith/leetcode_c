#include <vector>
#include <string>

using namespace std;

class Bitset {
public:
    vector<bool> b;
    bool tot = 0;
    int cnt = 0;
    Bitset(int size) {
        b = vector<bool>(size);
        cnt = 0;
    }
    
    void fix(int idx) {
        if (b[idx] == tot) {
            b[idx] = tot ^ 1;
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if (b[idx] ^ tot) {
            b[idx] = tot;
            cnt--;
        }
    }
    
    void flip() {
        tot ^= 1;
        cnt = int(b.size()) - cnt;
    }
    
    bool all() {
        return cnt == b.size();
    }
    
    bool one() {
        return cnt > 0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s(b.size(), '0');
        for (int i = 0; i < int(b.size()); i++) {
            if (b[i] ^ tot) s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }
};