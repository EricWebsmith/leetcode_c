#include <vector>
#include <iostream>

using namespace std;


    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n = s.size();
        int j = 0;
        int m = spaces.size();
        for (int i=0;i<n;i++){
            if(j < m && i == spaces[j]){
                ans += ' ';
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    string result = addSpaces("abc", v1);
    //cout << result << endl;
    return 0;
}