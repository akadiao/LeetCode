/*
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.

*/


#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if(A.size()<3 || A.size() >10000)
            return 0;
        int max_ = A[0];
        for(int i=1; i<A.size(); i++){
            if(A[i]>max_)
                max_ = A[i];
            else
                return i-1;
        }
    }
};


int main(){
    int a[] = {0, 2, 5, 4};
    vector<int> A;
    Solution slo;
    for(int i=0; i<sizeof(a)/sizeof(int); i++){
        A.push_back(a[i]);
    }
    cout<<slo.peakIndexInMountainArray(A)<<endl;

    return 0;
}
