#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) 
{
    if(x<0){
        return false;
    }

    if(x<10){
        return true;
    }

    if(x % 10 == 0)
    {
        return false;
    }

    unsigned int reverted_number = 0;

    while(x>reverted_number){
        reverted_number = reverted_number * 10 + x % 10;

        x /= 10;
    }

    if(reverted_number == x){
        return true;
    }

    if(reverted_number/10 == x){
        return true;
    }

    return false;
}

int main(){
    cout << isPalindrome(101) << endl;
    cout << isPalindrome(-101) << endl;
    cout << isPalindrome(21012) << endl;
}