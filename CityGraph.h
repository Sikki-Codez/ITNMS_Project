// CityGraph.h
#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include "Models.h"
#include <climits> // For INT_MAX

const int MAX_STATIONS = 100;

class CityGraph
{
private:
    Station *stations[MAX_STATIONS]; // Array to store station metadata
    Route *adjList[MAX_STATIONS];    // Adjacency List
    int stationCount;

public:
    CityGraph()
    {
        stationCount = 0;
        for (int i = 0; i < MAX_STATIONS; i++)
        {
            adjList[i] = nullptr;
            stations[i] = nullptr;
        }
    }

    void addStation(int id, string name)
    {
        if (id >= MAX_STATIONS)
        {
            cout << "ID too high!\n";
            return;
        }
        stations[id] = new Station{id, name, nullptr};
        stationCount++;
        cout << "Station " << name << " added.\n";
    }

    void addRoute(int src, int dest, int weight)
    {
        // Add edge src -> dest
        Route *newRoute = new Route{dest, weight, adjList[src]};
        adjList[src] = newRoute;

        // Add edge dest -> src (Undirected Graph)
        Route *newRoute2 = new Route{src, weight, adjList[dest]};
        adjList[dest] = newRoute2;
    }

    void BFS(int startID)
    {
        bool visited[MAX_STATIONS] = {false};
        int queue[MAX_STATIONS]; // Simple array based queue
        int front = 0, rear = 0;

        visited[startID] = true;
        queue[rear++] = startID;

        cout << "BFS Traversal: ";
        while (front < rear)
        {
            int curr = queue[front++];
            cout << curr << " ";

            Route *temp = adjList[curr];
            while (temp)
            {
                if (!visited[temp->destID])
                {
                    visited[temp->destID] = true;
                    queue[rear++] = temp->destID;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // Dijkstra's Shortest Path
    void DFS(int startID)
    {
        bool visited[MAX_STATIONS] = {false};
        cout << "DFS Traversal: ";
        DFSUtil(startID, visited);
        cout << endl;
    }

private:
    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";

        Route *temp = adjList[v];
        while (temp)
        {
            if (!visited[temp->destID])
                DFSUtil(temp->destID, visited);
            temp = temp->next;
        }
    }

    bool isCyclicUtil(int v, bool visited[], int parent)
    {
        visited[v] = true;
        Route *temp = adjList[v];
        while (temp)
        {
            if (!visited[temp->destID])
            {
                if (isCyclicUtil(temp->destID, visited, v))
                    return true;
            }
            else if (temp->destID != parent)
                return true;
            temp = temp->next;
        }
        return false;
    }

    struct Edge
    {
        int src, dest, weight;
    };

    int findParent(int parent[], int i)
    {
        if (parent[i] == i)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(int parent[], int rank[], int x, int y)
    {
        int xroot = findParent(parent, x);
        int yroot = findParent(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

public:
    void Dijkstra(int start, int end)
    {
        int dist[MAX_STATIONS];
        bool visited[MAX_STATIONS];
        int parent[MAX_STATIONS];

        for (int i = 0; i < MAX_STATIONS; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[start] = 0;

        for (int count = 0; count < MAX_STATIONS; count++)
        {
            // 1. Find min distance node not yet visited
            int min = INT_MAX, u = -1;
            for (int v = 0; v < MAX_STATIONS; v++)
            {
                if (!visited[v] && dist[v] <= min && stations[v] != nullptr)
                {
                    min = dist[v];
                    u = v;
                }
            }

            if (u == -1 || u == end)
                break;
            visited[u] = true;

            // 2. Relax neighbors
            Route *temp = adjList[u];
            while (temp)
            {
                if (!visited[temp->destID] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[temp->destID])
                {
                    dist[temp->destID] = dist[u] + temp->weight;
                    parent[temp->destID] = u;
                }
                temp = temp->next;
            }
        }

        if (dist[end] == INT_MAX)
        {
            cout << "No path exists.\n";
        }
        else
        {
            cout << "Shortest Distance: " << dist[end] << "\nPath: ";
            int curr = end;
            while (curr != -1)
            {
                cout << curr << " <- ";
                curr = parent[curr];
            }
            cout << "Start\n";
        }
    }

    bool detectCycle()
    {
        bool visited[MAX_STATIONS] = {false};
        for (int i = 0; i < MAX_STATIONS; i++)
        {
            if (stations[i] != nullptr && !visited[i])
            {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }

    void MST_Kruskal()
    {
        // Collect all edges
        Edge edges[1000];
        int edgeCount = 0;
        for (int i = 0; i < MAX_STATIONS; i++)
        {
            if (stations[i] != nullptr)
            {
                Route *temp = adjList[i];
                while (temp)
                {
                    if (i < temp->destID) // Avoid duplicates in undirected graph
                    {
                        edges[edgeCount].src = i;
                        edges[edgeCount].dest = temp->destID;
                        edges[edgeCount].weight = temp->weight;
                        edgeCount++;
                    }
                    temp = temp->next;
                }
            }
        }

        // Sort edges by weight (simple bubble sort)
        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        int parent[MAX_STATIONS];
        int rank[MAX_STATIONS] = {0};
        for (int i = 0; i < MAX_STATIONS; i++)
            parent[i] = i;

        cout << "MST Edges (Kruskal's Algorithm):\n";
        int mstWeight = 0;
        for (int i = 0; i < edgeCount; i++)
        {
            int x = findParent(parent, edges[i].src);
            int y = findParent(parent, edges[i].dest);

            if (x != y)
            {
                cout << edges[i].src << " - " << edges[i].dest << " (weight: " << edges[i].weight << ")\n";
                mstWeight += edges[i].weight;
                unionSets(parent, rank, x, y);
            }
        }
        cout << "Total MST Weight: " << mstWeight << "\n";
    }

    void deleteStation(int id)
    {
        if (stations[id] == nullptr)
        {
            cout << "Station not found.\n";
            return;
        }

        // Remove all routes connected to this station
        Route *temp = adjList[id];
        while (temp)
        {
            Route *next = temp->next;
            deleteRoute(id, temp->destID);
            temp = next;
        }
        adjList[id] = nullptr;

        delete stations[id];
        stations[id] = nullptr;
        stationCount--;
        cout << "Station " << id << " deleted.\n";
    }

    void deleteRoute(int src, int dest)
    {
        // Remove edge src -> dest
        Route *prev = nullptr;
        Route *curr = adjList[src];
        while (curr)
        {
            if (curr->destID == dest)
            {
                if (prev == nullptr)
                    adjList[src] = curr->next;
                else
                    prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // Remove edge dest -> src (undirected)
        prev = nullptr;
        curr = adjList[dest];
        while (curr)
        {
            if (curr->destID == src)
            {
                if (prev == nullptr)
                    adjList[dest] = curr->next;
                else
                    prev->next = curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void displayAllStations()
    {
        cout << "Connected Stations:\n";
        for (int i = 0; i < MAX_STATIONS; i++)
        {
            if (stations[i] != nullptr)
            {
                cout << "Station " << i << " (" << stations[i]->name << ") -> ";
                Route *temp = adjList[i];
                while (temp)
                {
                    cout << temp->destID << "(" << temp->weight << ") ";
                    temp = temp->next;
                }
                cout << "\n";
            }
        }
    }

    // Helper method for analytics - get busiest route
    void getBusiestRoute(int &src, int &dest, int &maxWeight)
    {
        maxWeight = 0;
        src = dest = -1;

        for (int i = 0; i < MAX_STATIONS; i++)
        {
            if (stations[i] != nullptr)
            {
                Route *temp = adjList[i];
                while (temp)
                {
                    if (i < temp->destID && temp->weight > maxWeight) // Avoid duplicates
                    {
                        maxWeight = temp->weight;
                        src = i;
                        dest = temp->destID;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    // Get route statistics for analytics
    void getRouteStatistics(int routeCounts[], int routeWeights[], int &totalRoutes)
    {
        totalRoutes = 0;
        for (int i = 0; i < MAX_STATIONS; i++)
        {
            routeCounts[i] = 0;
            routeWeights[i] = 0;
        }

        for (int i = 0; i < MAX_STATIONS; i++)
        {
            if (stations[i] != nullptr)
            {
                Route *temp = adjList[i];
                while (temp)
                {
                    if (i < temp->destID) // Count each edge once
                    {
                        routeCounts[totalRoutes] = 1;
                        routeWeights[totalRoutes] = temp->weight;
                        totalRoutes++;
                    }
                    temp = temp->next;
                }
            }
        }
    }
};

#endif // CITYGRAPH_H