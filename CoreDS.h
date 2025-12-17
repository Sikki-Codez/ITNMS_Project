// CoreDS.h
#ifndef COREDS_H
#define COREDS_H

#include "Models.h"

// --- 1. Passenger Queue (FIFO) ---
class PassengerQueue
{
private:
    Passenger *front;
    Passenger *rear;

public:
    PassengerQueue() { front = rear = nullptr; }

    void enqueue(int id, string name)
    {
        Passenger *newP = new Passenger{id, name, nullptr};
        if (rear == nullptr)
        {
            front = rear = newP;
            return;
        }
        rear->next = newP;
        rear = newP;
        cout << "Passenger added to queue.\n";
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!\n";
            return;
        }
        Passenger *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        cout << "Processed passenger: " << temp->name << endl;
        delete temp;
    }

    void display()
    {
        Passenger *temp = front;
        cout << "Passenger Queue: ";
        while (temp != nullptr)
        {
            cout << "[" << temp->name << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// --- 2. History Stack (LIFO) for Undo ---
class HistoryStack
{
private:
    LogEntry *top;

public:
    HistoryStack() { top = nullptr; }

    void push(string act, int id)
    {
        LogEntry *newLog = new LogEntry{act, id, top};
        top = newLog;
    }

    LogEntry pop()
    {
        if (top == nullptr)
            return {"EMPTY", -1, nullptr};
        LogEntry *temp = top;
        LogEntry data = *temp;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() { return top == nullptr; }
};

#endif // COREDS_H