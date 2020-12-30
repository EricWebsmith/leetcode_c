#include <string>
#include <iostream>

using namespace std;

    int lengthOfLastWord(string s) {
        int count = 0;
        bool start = false;
        //cout << s.size() << endl;
        for(int i=s.size()-1;i>=0;i--)    
        {
            cout << s[i];
            if(!start){
                if(s[i] != ' '){
                    start = true;
                    //count=1;
                }
            }

            if(start){
                if(s[i]!=' '){
                    count++;
                }
                else
                {
                    return count;
                }
                
            }
            
        }

        return count;
    }

int main(){

    cout << lengthOfLastWord("a") << endl;

}