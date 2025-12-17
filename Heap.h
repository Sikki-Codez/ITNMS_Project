// Heap.h - Priority Queue (Min Heap) for fastest vehicle, traffic prioritization
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <climits>
using namespace std;

struct HeapNode
{
    int priority;
    string data;
    int id;
};

class MinHeap
{
private:
    HeapNode *heap;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)].priority > heap[i].priority)
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l].priority < heap[smallest].priority)
            smallest = l;
        if (r < size && heap[r].priority < heap[smallest].priority)
            smallest = r;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int cap) : capacity(cap), size(0)
    {
        heap = new HeapNode[capacity];
    }

    ~MinHeap()
    {
        delete[] heap;
    }

    void insert(int priority, string data, int id)
    {
        if (size >= capacity)
        {
            cout << "Heap is full!\n";
            return;
        }

        heap[size].priority = priority;
        heap[size].data = data;
        heap[size].id = id;
        size++;
        heapifyUp(size - 1);
        cout << "Inserted [" << id << ": " << data << "] with priority " << priority << "\n";
    }

    HeapNode extractMin()
    {
        if (size == 0)
        {
            HeapNode empty;
            empty.priority = INT_MAX;
            empty.data = "EMPTY";
            empty.id = -1;
            return empty;
        }

        HeapNode min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return min;
    }

    HeapNode getMin()
    {
        if (size == 0)
        {
            HeapNode empty;
            empty.priority = INT_MAX;
            empty.data = "EMPTY";
            empty.id = -1;
            return empty;
        }
        return heap[0];
    }

    bool isEmpty() { return size == 0; }

    void display()
    {
        cout << "Heap Contents (Priority Queue):\n";
        for (int i = 0; i < size; i++)
        {
            cout << "[" << heap[i].id << ": " << heap[i].data << "] Priority: " << heap[i].priority << "\n";
        }
    }
};

#endif // HEAP_H
