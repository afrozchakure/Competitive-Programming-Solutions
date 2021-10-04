class MyCircularQueue
{
public:
    int front, rear, size, capacity;
    vector<int> queue;
    MyCircularQueue(int k)
    {
        queue = vector<int>(k, 0);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value)
    {
        if (!isFull())
        {
            if (rear == (capacity - 1))
                rear = 0;
            else
                rear++;
            queue[rear] = value;
            size++;
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (!isEmpty())
        {
            if (front == (capacity - 1))
                front = 0;
            else
            {
                front++;
            }
            size--;
            return true;
        }
        return false;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[rear];
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (size == capacity)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// Time Complexity - O(1)
// Space Complexity - O(N), using vector