/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
 

Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.

*/

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
