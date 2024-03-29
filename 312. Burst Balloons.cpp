//https://leetcode.com/problems/burst-balloons/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> c(n+2, vector<int>(n+2, 0));

        for(int l=1;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j = i+l-1;
                for(int k=i;k<=j;k++){
                    c[i][j] = std::max(c[i][j], nums[i-1]*nums[k]*nums[j+1] + c[i][k-1] + c[k+1][j]);
                }
            }
        }

        return c[1][n];
    }
};