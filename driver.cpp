#include <iostream>
#include "QueueFactory.cpp"
int main() {
    Queue<int>* q1 = QueueFactory<int>::GetQueue(10);
    for (int i = 0; i < 100; i++) {
        int num = rand() % 3 - 1;
        cout << i << ": Random number generated: " << num << "     ";
        if (num == -1) {
            if (!q1->isEmpty()) {
                cout << "Dequeueing..." << endl;
                q1->dequeue();
            } else {
                cout << "Queue is empty, cannot dequeue." << endl;
            }
        } else {
            if (!q1->isFull()) {
                cout << "Enqueueing..." << endl;
                q1->enqueue(num);
            } else {
                cout << "Queue is full, cannot enqueue." << endl;
            }
        }
    }

    Queue<int>* q2 = QueueFactory<int>::GetQueue();

    // 100 random numbers between -1 and 2
    for (int i = 0; i < 100; i++) {
        int num = rand() % 3 - 1;
        cout << i << ": Random number generated: " << num << "     ";
        if (num == -1) {
            if (!q2->isEmpty()) {
                cout << "Dequeueing..." << endl;
                q2->dequeue();
            } else {
                cout << "Queue is empty, cannot dequeue." << endl;
            }
        } else {
            if (!q2->isFull()) {
                cout << "Enqueueing..." << endl;
                q2->enqueue(num);
            } else {
                cout << "Queue is full, cannot enqueue." << endl;
            }
        }
    }

    return 0;

}