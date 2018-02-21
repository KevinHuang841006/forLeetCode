/*
You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

小心：洗衣機會跑，且可以有很多洗衣機同時給其中1台洗衣機1件衣服
*/

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) return -1;
        int res = 0, cnt = 0, avg = sum / machines.size();
        for (int m : machines) {
            cnt += m - avg;
            res = max(res, max(abs(cnt), m - avg));
        }
        return res;
    }
};
