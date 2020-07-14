//Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

//Structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};

void MyQueue:: push(int x) {
    if(rear==NULL) {
        rear = new QueueNode(x);
        front = rear;
    } else {
        rear->next = new QueueNode(x);
        rear = rear->next;
    }
}

int MyQueue :: pop() {
    if(front == NULL)   return -1;
    int val;
    if(front==rear) {
        val = front->data;
        delete(front);
        front = rear = NULL;
    } else {
        QueueNode* temp = front->next;
        val = front->data;
        delete(front);
        front = temp;
    }
    return val;
}