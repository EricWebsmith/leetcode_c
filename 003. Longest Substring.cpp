#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    map<char, int> m;
    int anchor = 0;
    for(int j=0;j<n;j++){
        char c = s[j];
        auto it = m.find(c);
        if(it!=m.end()){
            anchor = max(it->second, anchor);
        }
        ans = max(ans, j-anchor+1);
        m[c] = j+1;
    }    
    return ans; 
}

int main(){
    map<char, int> m;
    m.emplace('a',1);
    cout << m['1'] << endl;
    m.emplace('a',12);
    cout << m['a'] << endl;
    cout << lengthOfLongestSubstring("alouzxilkaxkufsu") << endl;
    cout << lengthOfLongestSubstring("abba") << endl;
    cout << lengthOfLongestSubstring("cdd") << endl;
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << (lengthOfLongestSubstring("pwwkew")==3) << endl;
    cout << (lengthOfLongestSubstring("")==0) << endl;
    cout << (lengthOfLongestSubstring(" ")==1) << endl;
    cout << lengthOfLongestSubstring("au") << (lengthOfLongestSubstring("au")==2) << endl;
    cout << (lengthOfLongestSubstring("aab")==2) << endl;
    cout << (lengthOfLongestSubstring("pwwkew")==3) << endl;
}