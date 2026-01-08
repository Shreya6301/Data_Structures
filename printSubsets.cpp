#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& answer, int i) {
    // base case
    if (i == arr.size()) {
        for (int val : answer) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // inclusion of element in subset
    answer.push_back(arr[i]);
    printSubsets(arr, answer, i + 1);

    // exclusion of element in subset
    answer.pop_back(); // backtrack
    printSubsets(arr, answer, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> answer; // store the subsets

    printSubsets(arr, answer, 0);
    return 0;
}
