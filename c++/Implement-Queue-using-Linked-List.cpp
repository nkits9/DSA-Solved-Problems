//Structure of a node in Queue
struct QueueNode {
    int data;
    QueueNode *next;
    QueueNode(int a) {
        data = a;
        next = NULL;
    }
};


class MyQueue {
    private:
    QueueNode *front;
    QueueNode *rear;
    
    public:
    MyQueue() {
        front = rear = NULL;
    }
    
    public:
    void push(int x) {
        if(rear==NULL) {
            rear = new QueueNode(x);
            front = rear;
        } else {
            rear->next = new QueueNode(x);
            rear = rear->next;
        }
    }
    
    public:
    int pop() {
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
};
