#include<iostream>
#include<list>
using namespace std;

class List{
   list<int> ll;

    public:

    void push(int value){
        ll.push_front(value);
    }

    void pop(){
        ll.pop_front();
    }
    
    int top(){
        return ll.front();

    }

    bool empty(){
        return ll.size() == 0;
    }
};

int main(){
     List ll;

    ll.push(10);
    ll.push(30);
    ll.push(6);

    ll.pop();

    while(!ll.empty()){
        cout << ll.top() << " ";
        ll.pop();

    }
    cout << endl;
    return 0;
}