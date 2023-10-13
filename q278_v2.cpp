
/* Author: Soumik Mondal (soumikmondal1727@gmail.com)
   Desc: First Bad Version */

/* QUESTION: You are a product manager and currently leading a team to develop a new product. Unfortunately, the 
latest version of your product fails the quality check.Since each version is developed based on the previous version, 
all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int start = 0;
        long int end = n;
        long int minVersion = -1;

        while( start<=end){
            long int mid = (start+end)/2;
            if(isBadVersion(mid) == 1){
                minVersion = mid ;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return minVersion;
    }
};

// Approach:
// 1. Use binary search to find a minimum bad version using the given API.
// 2. If found, again search for another bad version toward the left of the previous bad element by reducing the search space.
// 3. Using this approach find the first bad version out of the vector.
// 4. Return minVersion(first bad version).

// Time Complexity: O(logn)
// Space Complexity: O(1)
