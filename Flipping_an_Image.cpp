/*

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

*/




#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
        if(A.size()>20 || A.size()<1)
            return A;
        for(int i=0; i<A.size(); i++){
            if(A[i].size()>20 || A[i].size()<1)
                return A;
            reverse(A[i].begin(), A[i].end());
            for(int j=0; j<A[i].size(); j++){
                if(A[i][j]!=0 && A[i][j]!=1)
                    return A;
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};


int main(){
    int A[4][4]={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    Solution slo;
    vector<vector<int> > vector_A;
    for(int i=0; i<4; i++){
        vector<int> vector_a;
        for(int j=0; j<4; j++){
            vector_a.push_back(A[i][j]);
            cout<<A[i][j];
        }
        vector_A.push_back(vector_a);
        cout<<"\n";
    }
    cout<<"============"<<endl;
    slo.flipAndInvertImage(vector_A);
    for(int i=0; i<vector_A.size(); i++){
        for(int j=0; j<vector_A[i].size(); j++){
            cout<<vector_A[i][j];
        }
        cout<<"\n";
    }
    return 0;
}


