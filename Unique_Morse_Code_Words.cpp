#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size()>100)
            return 0;
        string morsecode[] = {".-","-...","-.-.","-..",".",
                              "..-.","--.","....","..",".---",
                              "-.-",".-..","--","-.","---",".--.",
                              "--.-",".-.","...","-","..-","...-",
                              ".--","-..-","-.--","--.."};
        vector<string> word2morses;
        for(int i=0; i<words.size(); i++){
            string morse;
            if(words[i].length()<1 || words[i].length()>12)
                return 0;
            for(int j=0; j<words[i].length(); j++)
                morse.append(morsecode[(int)words[i][j]-97]);
//            cout<<morse<<endl;
            word2morses.push_back(morse);
        }
        sort(word2morses.begin(), word2morses.end());
        word2morses.erase(unique(word2morses.begin(), word2morses.end()), word2morses.end());
        return word2morses.size();
    }
};

int main(){
    string words[5] = {"zocd","gjkl","hzqk","hzgq","gjkl"};
    Solution slo;
    vector<string> words_vector;
    for(int i=0; i<5; i++)
        words_vector.push_back(words[i]);

    int i = slo.uniqueMorseRepresentations(words_vector);
    cout<<i<<endl;
    return 0;
}
