#include <iostream>

using namespace std;

int myAtoi(string s) {
    int result=0;
    
    
    int i=0;
    while(s[i]==' '){
        i++;
    }
    
    int sign=1;
    bool has_sign = false;
    while(s[i]=='-' || s[i]=='+'){
        if(has_sign){
            return 0;
        }
        has_sign=true;
        sign = s[i]=='+'?1:-1;
        i++;
    }

    while(s[i]>='0' and s[i]<='9'){
        char c = s[i];
        if(result>214748364){
            return sign==1?2147483647:-2147483648;
        }
        else if(sign==1 && result == 214748364 && c-'0'>=7){
            return 2147483647;
        }else if(sign==-1 && result == 214748364 && c-'0'>=8){
            return -2147483648;
        }
        result = result * 10 - '0' + c;
        i++;
    }

    return sign * result;
}

void test(string s, int expected){
    int actual = myAtoi(s);
    bool right = actual==expected;
    cout<< s << "\t" << myAtoi("00000-42a1234") << "\t" << right << endl; 
}

int main(){
    test("   +0 123", 0);
    test("00000-42a1234", 0);    
    test("21474836460", 2147483647);
    test("42", 42);
    test("+-12", 0);
    test("42", 42);
    test("   -42", -42);
    cout<<myAtoi("4193 with words")<<endl;
    cout<<myAtoi("words and 987")<<endl;
    cout<<myAtoi("2147483647")<<endl;
    cout<<myAtoi("2147483648")<<endl;
    cout<<myAtoi("-91283472332")<<endl;
    cout<<myAtoi("42")<<endl;
    cout<<myAtoi("42")<<endl;
}