#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    // stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> answer(price.size()); // ✅ initialize with size
    stack<int> s;

    for (int i = 0; i < price.size(); i++) {
        // Pop indices with smaller or equal price
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        if (s.empty()) {
            answer[i] = i + 1;  // span = i+1 if no greater element to left
        } else {
            answer[i] = i - s.top(); // span = distance between current and top
        }

        s.push(i);
    }

    for (int val : answer) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}