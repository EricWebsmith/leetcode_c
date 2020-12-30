/*
https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> result;

    for (int i=0;i<nums.size();i++)
    {
        m.insert(pair<int, int>(nums[i],i));
    }

    for(int i=0; i<nums.size(); i++)
    {
        cout << m.count(target-nums[i]) << m[target-nums[i]] << endl;
        if(m.count(target-nums[i])==1 && m[target-nums[i]]!=i)
        {
            result.push_back(i);
            result.push_back(m[target-nums[i]]);
            return result;
        }
    }
    return result;

}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char* argv[])
{
    vector<int> v{2,7,11,15};
    vector<int> ret=twoSum(v, 9);
    string out = integerVectorToString(ret);
    cout << out << endl;

    return 0;
}