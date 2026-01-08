#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) return false; // single book too big

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
            if (students > m) return false;
        }
    }
    return true;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxBook = max(maxBook, arr[i]);
    }

    int start = maxBook;
    int end = sum;
    int answer = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isValid(arr, n, m, mid)) {
            answer = mid;
            end = mid - 1; // try smaller max pages
        } else {
            start = mid + 1;
        }
    }
    return answer;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    cout << allocateBooks(arr, n, m);
}
