#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    vector<int> v = s.getConcatenation(nums);
    for(int i=0;i<v.size();i++){
        cout << v.at(i) << ", ";
    }
    cout << endl;
    return 0;
}

/*
Runtime: 7 ms, faster than 88.44% of C++ online submissions for Concatenation of Array.
Memory Usage: 13 MB, less than 17.71% of C++ online submissions for Concatenation of Array.
*/