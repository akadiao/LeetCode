#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0;i<str.length();i++)
            if(str[i]>=65 && str[i]<=90)
                str[i] = (int)str[i] + 32;
        return str;
    }
};

int main(){
    string str ="aAAbbbb";
    Solution slo;
    cout<<"str="<<slo.toLowerCase(str)<<endl;
    return 0;
}
