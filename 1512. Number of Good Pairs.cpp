#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        map<int, int> counts;
        for (int i = 0; i < nums.size(); i++)
        {
            counts[nums[i]]++;
        }

        int ans = 0;
        for(const auto p: counts){
            if(p.second>=2){
                ans+= p.second * (p.second-1) /2;
            }
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<int> vect{1, 2, 3, 1, 1, 3};
    cout << s.numIdenticalPairs(vect) << endl;

    vector<int> vect2{1, 1, 1, 1};
    cout << s.numIdenticalPairs(vect2) << endl;
}