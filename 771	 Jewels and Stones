#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int numJinS = 0;
        for(int i=0; i<S.length(); i++)
            for(int j=0; j<J.length(); j++)
                if(J[j]==S[i])
                    numJinS++;
        return numJinS;
    }
};


int main(){
    string str ="aAAbbbb";
    string s= "aA";
    Solution slo;
    int n = slo.numJewelsInStones(s, str);
    printf("num=%d\n", n);
    return 0;
}
