#include <iostream>
using namespace std;

// Abstract class template for 1D dynamic array
template <typename T>
class AbstractArray {
public:
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual T Front() = 0;
    virtual T Rear() = 0;
    virtual void enqueue(T val) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;

    virtual ~AbstractArray() {}
};

// Derived Queue class template
template <typename T>
class Queue : public AbstractArray<T> {
    T* arr;
    int capacity;
    int count;
    int front;
    int rear;

public:
    Queue(int cap = 5) {
        capacity = cap;
        arr = new T[capacity];
        count = 0;
        front = 0;
        rear = -1;
    }

    bool isFull() override {
        return count == capacity;
    }

    bool isEmpty() override {
        return count == 0;
    }

    int size() override {
        return count;
    }

    T Front() override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return arr[front];
    }

    T Rear() override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return arr[rear];
    }

    void enqueue(T val) override {
        if (isFull()) {
            cout << "Queue is full! Resizing..." << endl;
            resize();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
        cout << val << " enqueued successfully." << endl;
    }

    void dequeue() override {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully." << endl;
        front = (front + 1) % capacity;
        count--;
    }

    void resize() override {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        for (int i = 0; i < count; i++)
            newArr[i] = arr[(front + i) % capacity];

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = count - 1;
        capacity = newCapacity;
        cout << "Queue resized to capacity: " << capacity << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    cout << "=== Integer Queue ===" << endl;
    Queue<int> q(3); // capacity of 3

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    // This will trigger resize
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    cout << "\n=== String Queue ===" << endl;
    Queue<string> q2(2);
    q2.enqueue("Ali");
    q2.enqueue("Sara");
    q2.display();
    q2.enqueue("Ahmed"); // triggers resize
    q2.display();

    return 0;
}