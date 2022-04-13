#include <iostream>
#include <vector>

using namespace std;

    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int result = 0;
        unsigned int mask = 1;
        for(int i=0;i<32;++i){
            int count = 0;
            for(const int num : nums){
                if((num & mask)>0){
                    count++;
                }
            }
            result += count * (n - count);
            mask <<= 1;
        }
        return result;
    }

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout << totalHammingDistance(v1) << endl;

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    cout << totalHammingDistance(v2) << endl;
}