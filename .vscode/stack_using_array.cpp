#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;

    public:

    void push(int value){
        vec.push_back(value);
    }

    void pop(){
        vec.pop_back();
    }
    
    int top(){
        return vec[vec.size() -1];

    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){
     Stack s;

    s.push(10);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();

    }
    cout << endl;
    return 0;
}



