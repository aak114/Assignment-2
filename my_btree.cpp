#include <iostream>

using namespace std;

template <typename T>
struct treeNode {
    T *data;
    struct treeNode * left;
    struct treeNode * right;
};


class my_btree{
    public:
    void addNode(struct treeNode * node){}
    void deleteNode(){}
    int treeSize(){}
    int subtreeSize(){}
    void postOrderPrint(){}
    void preOrderPrint(){}
    void inOrderPrint(){}


    private:
    struct treeNode * root;
    int treesize;
    void addNode(struct treeNode* current,struct treeNode* node){
        if (current == NULL){
            *current = node;
        } else {
            addNode(&(current->left), node);
        }

        
    }
    
    
    
};



int main(){

}