#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<int, int> m;
        for(int i=0;i<jewels.size();i++){
            m[jewels[i]] = 0;
        }

        int ans = 0;
        for(int i=0;i<stones.size();i++){
            if(m.find(stones[i])!=m.end()){
                ans++;
            }
        }

        return ans;
    }
};