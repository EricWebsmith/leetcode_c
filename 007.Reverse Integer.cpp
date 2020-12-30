#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int reverse(int x) {
    const int MAX = 2e31 -1;
    const int MIN = -2e31;
    int res = 0;

    while(x){
        if(res > MAX / 10) { return 0; }
        if(res < MIN / 10) { return 0; }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main(){
    cout << reverse(-2147483648) << endl;
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(1534236469) << endl;
    cout << INT_MAX << endl;
    cout << reverse(pow(2, 31)) << endl;
    cout << reverse(10) << endl;
}