class MyQueue {
private:
    int arr[10001];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

void MyQueue :: push(int x) {
    arr[rear++] = x;
}

int MyQueue :: pop() {
    if(front == rear) 
        return -1;
    return arr[front++];
}
