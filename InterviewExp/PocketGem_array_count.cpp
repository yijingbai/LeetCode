#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> repeat_times(vector<int> A, vector<int> B) {
        map<int, int> repeat_map;
        map<int, int> value_map;
        for (int i = 0; i < A.size(); i++) {
            if (repeat_map.find(A[i]) == repeat_map.end()) {
                repeat_map[A[i]] = 1;
            } else {
                repeat_map[A[i]]++;
            }
        }
        map<int, int>::iterator it;
        for (it = repeat_map.begin(); it != repeat_map.end(); it++) {
            int key = it->first;
            int value = it->second;
            repeat_map[value] = key;
        }

        vector<int> result;
        for (int i = 0; i < B.size(); i++) {
            int key = B[i];
            result.push_back(value_map[key]);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 3, 3, 3, 3, 6, 6, 6, 6, 6, 8, 8};
    vector<int> B = {5, 2, 4, 9};
    vector<int> C = s.repeat_times(A, B);
    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << endl;
    }
}
