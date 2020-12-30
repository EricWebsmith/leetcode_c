#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
        if(target<=nums[i]){
            return i;
        }
    }
    return nums.size();
}

int main(){
    vector<int> v = {1,2,3};
    cout << searchInsert(v, 3) << endl;
    vector<int> v2 = {1,2,4};
    cout << searchInsert(v2, 3) << endl;
}