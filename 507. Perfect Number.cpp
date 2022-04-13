#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) { return false; }
        int sum = 1;
        for(int i = 2; i * i < num; i++)
        {
            if(num % i != 0)
            {
                continue;
            }

            sum += num / i + i;
        }

        return sum == num;
    }
};


int main(){
    clock_t start, end;
    start = clock();
    Solution s = Solution();
    for (int i = 1; i <= 100000000; i++)
    {
        if (s.checkPerfectNumber(i))
        {
            cout << i << endl;
        }
    }
    end = clock();

    float seconds = ((float) end - start)/CLOCKS_PER_SEC;
    cout << "Spent " << seconds << " seconds." << endl;
    return 0;
}

/*
output

6
28
496
8128
33550336
Spent 1570.47 seconds.
*/