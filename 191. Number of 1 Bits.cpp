#include <iostream>

using namespace std;

    int hammingWeight(uint32_t n) {
        int ones = 0;
        while(n>0){
            n = n & (n-1);
            ones++;
        }    
        return ones;
    }

int main(){
    cout << hammingWeight(0) << endl;
    cout << hammingWeight(1) << endl;
    cout << hammingWeight(2) << endl;
    cout << hammingWeight(3) << endl;
    cout << hammingWeight(1024) << endl;
    cout << hammingWeight(0b11111) << endl;
}