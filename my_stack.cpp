#include <iostream>
#include <list>

using namespace std;

template <typename T> class my_stack{
    
    public:
    my_stack(){}
    /*
    Returns: true if stack empty, false otherwise
    */
    bool empty(){return l.empty();}

    /*
    Requires: Adress of element of type T
    Modifies: adds item to stack (to the back)
    */
    void push(const T &item){l.push_back(item);}

    /*
    Returns: last element in stack
    */
    T& top(){return l.back();}

    /*
    Modifies: Removes last element from stack
    */
    void pop(){l.pop_back();}

    /*
    Requires: non empty stack of type T
    Returns: new stack<T> of type T, with elements of this stack + elements of s in consecutive order (last item in new stack is last item in second stack)
    */
    my_stack<T> operator+(my_stack<T> s){
        my_stack<T> s2;
        for (int i = 0; i < l.size(); i++){
            T current = l.front();
            l.pop_front();
            s2.push(current);
            l.push_back(current);
        }
        for (int i = 0; i < s.l.size(); i++){
            T current = s.l.front();
            s.l.pop_front();
            s2.push(current);
            s.l.push_back(current);
        }
        return s2;
    }

    private:
    list<T> l;
};

int main(){
    my_stack<int> s;
    my_stack<int> s1;
    
    // cout << s.empty() << endl;
    s.push(7);
    s1.push(5);
    s1.push(9);
    // cout << s.empty() << endl;
    // cout << s.top()++ << endl;
    // cout << s.top() << endl;

    my_stack<int> s2 = s + s1;
    cout << s2.top() << endl;
}