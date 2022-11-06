#include <iostream>
#include <list>

using namespace std;

template <typename T> class my_stack{
    
    public:
    my_stack(){}
    bool empty(){return l.empty();}
    void push(const T &item){l.push_back(item);}
    T& top(){return l.back();}
    void pop(){l.pop_back();}
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