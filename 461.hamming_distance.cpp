#include <iostream>

using namespace std;
    
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int diff = 0;
        while(z>0){
            z = z & (z-1);
            diff++;
        }    
        return diff;
    }


int main(){
    cout << hammingDistance(1, 4) << endl;
    cout << hammingDistance(7, 8) << endl;
    cout << hammingDistance(2, 3) << endl;
}