#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> arr){
    vector<int> answer(arr.size(), 0);
    stack<int> s;

    for(int i=0; i<arr.size(); i++){
        while(s.size() >0 && s.top() >= arr[i]){
            s.pop();
        }

        if(s.empty()){
            answer[i] = -1;
        }else{
            answer[i] = s.top();
        }

        s.push(arr[i]);
    }
    
    return answer;

}

int main(){
    vector<int> arr = {3, 1, 0, 8, 6};

    vector<int> answer = prevSmallerElement(arr);

    for(int val: answer){
        cout << val << " ";
    }
    cout <<endl;

    return 0;
}