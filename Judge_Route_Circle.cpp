/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle,
which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. 
The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be 
true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false

*/


#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.empty())
            return true;
        int RL=0, UD=0;
        for(int i=0; i<moves.length(); i++){
            switch (moves[i]) {
            case 'R': RL++; break;
            case 'L': RL--; break;
            case 'U': UD++; break;
            case 'D': UD--; break;
            }
            //cout<<moves[i]<<"--RL:"<<RL<<"--UD:"<<UD<<endl;
        }
        if(RL || UD)
            return false;
        else
            return true;
    }
};


int main(){
    string moves = "LRUDUD";
    Solution slo;
    cout<<slo.judgeCircle(moves)<<endl;
    return 0;
}


