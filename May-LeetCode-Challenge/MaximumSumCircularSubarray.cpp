/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/ */


class Solution {
private: 
    int modifiedKadane(vector<int>&A) {
        int globalMax = A[0];
        int localMax = A[0];
        for(int i = 1; i < A.size(); i++){
            if(A[i] + localMax > A[i]){
                localMax = A[i] + localMax;
            }
            else{
                localMax = A[i];
            }
            if(globalMax < localMax)
            {
                globalMax = localMax; 
            }
        }
        return globalMax;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int simpleArrayMax = modifiedKadane(A);
        vector<int> B;
        int sum = 0;
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            B.push_back(-1 * A[i]);
        }
        //sum - remove lowest sum
        int circularArrayMax = modifiedKadane(B) + sum;
        return (circularArrayMax != 0 && circularArrayMax > simpleArrayMax) ? circularArrayMax : simpleArrayMax;
        
    }
};
