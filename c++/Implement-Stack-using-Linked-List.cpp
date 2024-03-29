//Structure of the node of the stack.
struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


class MyStack {
    private:
    StackNode *top;

    public:
    MyStack() {
        top = NULL;
    }

    public:
    void push(int x) {
        if(top==NULL) {
            top = new StackNode(x);
        }
        else {
            StackNode* temp = new StackNode(x);
            temp->next = top;
            top = temp;
        }
    }

    public:
    int pop() {
        if(top==NULL)   return -1;

        StackNode *temp = top->next;
        int val = top->data;
        delete(top);
        top = temp;

        return val;
    }
}
