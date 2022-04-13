#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            ans.push_back(ans[i-1]+nums[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> vect{1,2,3,4};
    Solution s;
    vector<int> ans = s.runningSum(vect);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ",";
    }
    return 0;
}