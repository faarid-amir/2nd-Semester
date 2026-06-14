#include <iostream>
#include <string>
using namespace std;

template <typename T>
class AbstractArray
{
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

template <typename T>
class Queue : public AbstractArray<T>
{
    T *arr;
    int capacity;
    int count;
    int front;
    int rear;

public:
    Queue(int cap = 5)
    {
        capacity = cap;
        arr = new T[capacity];
        count = 0;
        front = 0;
        rear = -1;
    }

    bool isFull() override { return count == capacity; }
    bool isEmpty() override { return count == 0; }
    int size() override { return count; }

    T Front() override
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return arr[front];
    }

    T Rear() override
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return arr[rear];
    }

    void enqueue(T val) override
    {
        if (isFull())
            resize();
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }

    void dequeue() override
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    void resize() override
    {
        int newCapacity = capacity * 2;
        T *newArr = new T[newCapacity];
        for (int i = 0; i < count; i++)
            newArr[i] = arr[(front + i) % capacity];
        delete[] arr;
        arr = newArr;
        front = 0;
        rear = count - 1;
        capacity = newCapacity;
    }

    ~Queue() { delete[] arr; }
};

// ---- Print Shop Class ----
class PrintShop
{
    Queue<string> jobQueue;
    bool printerIdle;

public:
    PrintShop() : jobQueue(5)
    {
        printerIdle = true;
    }

    // Add a print job to the queue
    void addJob(string job)
    {
        cout << "Job received: \"" << job << "\" added to queue." << endl;
        jobQueue.enqueue(job);

        // If printer is idle, start printing immediately
        if (printerIdle)
            processJob();
    }

    // Process the next job in queue
    void processJob()
    {
        if (!jobQueue.isEmpty())
        {
            printerIdle = false;
            string job = jobQueue.Front();
            jobQueue.dequeue();
            cout << "Printing: \"" << job << "\"..." << endl;
            cout << "\"" << job << "\" completed!" << endl;

            // Check if more jobs exist
            if (!jobQueue.isEmpty())
            {
                cout << "Next job found in queue. Continuing..." << endl;
                processJob(); // process next job
            }
            else
            {
                printerIdle = true;
                cout << "No more jobs. Printer is now idle." << endl;
            }
        }
    }
};

int main()
{
    PrintShop shop;

    cout << "===== Print Shop Simulation =====" << endl
         << endl;

    shop.addJob("Resume.pdf");
    cout << endl;
    shop.addJob("Assignment.docx");
    cout << endl;
    shop.addJob("Invoice.pdf");
    cout << endl;
    shop.addJob("Report.docx");

    return 0;
}