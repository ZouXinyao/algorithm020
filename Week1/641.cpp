class MyCircularDeque {
private:
    vector<int> myDeque;
    int length;
    int front;
    int rear;
    int getPrevIdx(int idx) { return idx == 0 ? myDeque.size() - 1 : idx - 1; }
    int getNextIdx(int idx) { return (idx == myDeque.size() - 1) ? 0 : idx + 1; }
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): myDeque(vector<int>(k + 1, -1)), length(0), front(0), rear(1) {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        myDeque[front] = value;
        front = getPrevIdx(front);
        ++length;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        myDeque[rear] = value;
        rear = getNextIdx(rear);
        ++length;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        front = getNextIdx(front);
        myDeque[front] = -1;
        --length;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = getPrevIdx(rear);
        myDeque[rear] = -1;
        --length;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return myDeque[getNextIdx(front)];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return myDeque[getPrevIdx(rear)];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return length == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return length == myDeque.size() - 1;
    }
};