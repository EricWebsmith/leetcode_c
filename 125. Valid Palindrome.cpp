#include <iostream>

using namespace std;



    bool isPalindrome(string s) {
        if(s.size()<=1) return true;

        int head = 0;
        int tail = s.size() - 1;
        char char_head = ' ';
        char char_tail = ' ';

        while(head < tail){

            while(char_head==' ' && head<s.size())
            {
                if(s[head]>='a' && s[head]<='z')
                {
                    char_head = s[head];
                }
                else if(s[head]>='0' && s[head]<='9')
                {
                    char_head = s[head];
                }
                else if(s[head]>='A' && s[head]<='Z')
                {
                    char_head = s[head] + 32;
                }
                head++;
            }

            while(char_tail==' ' && tail>=0)
            {
                if(s[tail]>='a' && s[tail]<='z')
                {
                    char_tail = s[tail];
                }
                else if(s[tail]>='0' && s[tail]<='9')
                {
                    char_tail = s[tail];
                }
                else if(s[tail]>='A' && s[tail]<='Z')
                {
                    char_tail = s[tail] + 32;
                }
                tail--;
            }

            if(char_head!=char_tail){
                return false;
            }
            
            char_head=' ';
            char_tail=' ';
        }

        return true;
    }

    int main(){
        cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
        cout << !isPalindrome("race a car") << endl;
        cout << isPalindrome(".,") << endl;
        cout << isPalindrome("a.") << endl;
        cout << isPalindrome("") << endl;
        cout << isPalindrome(" ") << endl;
        cout << !isPalindrome("0P") << endl;
    }