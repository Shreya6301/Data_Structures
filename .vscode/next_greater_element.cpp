#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};

    stack<int> s;
    vector<int> answer(arr.size(), 0);

    // ✅ traverse from right to left
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            answer[i] = -1;
        } else {
            answer[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int val : answer) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
