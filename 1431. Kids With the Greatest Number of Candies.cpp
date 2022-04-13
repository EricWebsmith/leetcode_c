#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(),candies.end());
        cout << max << endl;
        vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            ans.push_back((candies[i]+extraCandies)>=max);
        }

        return ans;
    }
};

int main(){
    vector<int> candies{2,3,5, 1,3};
    Solution s;
    vector<bool> ans = s.kidsWithCandies(candies, 3);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ", ";
    }
    cout << endl;
}