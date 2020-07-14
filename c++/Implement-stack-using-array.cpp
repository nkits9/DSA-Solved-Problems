class MyStack {
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack :: push(int x) {
    top++;
    arr[top]=a;
}

int MyStack :: pop() {
    if(top == -1)   return -1;
    int x = arr[top];
    top--;
    return x;
}
