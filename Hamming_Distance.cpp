/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/



#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int max_, min_, num;
        num = 0;
        if(x>y){
            max_=x;
            min_=y;
        }
        else{
            max_=y;
            min_=x;
        }
        while(max_){
            if((max_%2)!=(min_%2))
                num++;
//            cout<<max_%2<<"--"<<min_%2<<endl;
            max_/=2;
            min_/=2;
        }
     return num;
    }
};


int main(){
    Solution slo;
    cout<<slo.hammingDistance(13,16)<<endl;
    return 0;
}


