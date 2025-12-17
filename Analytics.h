// Analytics.h - Advanced DSA Analytics & Reporting Module
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "CityGraph.h"
#include "VehicleMap.h"
#include "Tree.h"
#include "Heap.h"
#include "CoreDS.h"
#include <iostream>
#include <climits>
using namespace std;

class Analytics
{
private:
    // Hash table for station frequency counting
    struct FrequencyNode
    {
        int stationID;
        int count;
        FrequencyNode *next;
        FrequencyNode(int id, int c) : stationID(id), count(c), next(nullptr) {}
    };

    FrequencyNode *freqTable[100]; // Hash table for station frequency
    const int FREQ_TABLE_SIZE = 100;

    int hashFunction(int id)
    {
        return id % FREQ_TABLE_SIZE;
    }

public:
    Analytics()
    {
        for (int i = 0; i < FREQ_TABLE_SIZE; i++)
            freqTable[i] = nullptr;
    }

    // 1. Most Crowded Station (Hash Frequency Count)
    void recordStationVisit(int stationID)
    {
        int idx = hashFunction(stationID);
        FrequencyNode *curr = freqTable[idx];

        // Search for existing entry
        while (curr != nullptr)
        {
            if (curr->stationID == stationID)
            {
                curr->count++;
                return;
            }
            curr = curr->next;
        }

        // Insert new entry
        FrequencyNode *newNode = new FrequencyNode(stationID, 1);
        newNode->next = freqTable[idx];
        freqTable[idx] = newNode;
    }

    void findMostCrowdedStation(CityGraph &city)
    {
        int maxCount = 0;
        int mostCrowdedID = -1;

        for (int i = 0; i < FREQ_TABLE_SIZE; i++)
        {
            FrequencyNode *curr = freqTable[i];
            while (curr != nullptr)
            {
                if (curr->count > maxCount)
                {
                    maxCount = curr->count;
                    mostCrowdedID = curr->stationID;
                }
                curr = curr->next;
            }
        }

        if (mostCrowdedID != -1)
        {
            cout << "\n=== Most Crowded Station Analysis ===\n";
            cout << "Station ID: " << mostCrowdedID << "\n";
            cout << "Visit Count: " << maxCount << "\n";
            cout << "Using: Hash Table Frequency Count\n";
            cout << "=====================================\n";
        }
        else
        {
            cout << "No station visits recorded yet.\n";
        }
    }

    void displayStationFrequencies()
    {
        cout << "\n=== Station Visit Frequencies (Hash Table) ===\n";
        bool found = false;
        for (int i = 0; i < FREQ_TABLE_SIZE; i++)
        {
            FrequencyNode *curr = freqTable[i];
            while (curr != nullptr)
            {
                cout << "Station " << curr->stationID << ": " << curr->count << " visits\n";
                curr = curr->next;
                found = true;
            }
        }
        if (!found)
            cout << "No visits recorded.\n";
        cout << "==============================================\n";
    }

    // 2. Busiest Route (Graph Edge Weight Statistics)
    void findBusiestRoute(CityGraph &city)
    {
        int src, dest, maxWeight;
        city.getBusiestRoute(src, dest, maxWeight);

        cout << "\n=== Busiest Route Analysis ===\n";
        if (src != -1 && dest != -1)
        {
            cout << "Busiest Route: " << src << " -> " << dest << "\n";
            cout << "Edge Weight (Traffic Density): " << maxWeight << "\n";
            cout << "Higher weight indicates more traffic/busier route\n";
        }
        else
        {
            cout << "No routes found in the network.\n";
        }
        cout << "Using: Graph Edge Weight Statistics\n";
        cout << "==================================\n";
    }

    // Helper function to analyze route weights (requires graph access)
    void analyzeRouteWeights(CityGraph &city)
    {
        int routeCounts[1000];
        int routeWeights[1000];
        int totalRoutes = 0;

        city.getRouteStatistics(routeCounts, routeWeights, totalRoutes);

        cout << "\n=== Route Weight Statistics ===\n";
        cout << "Total Routes: " << totalRoutes << "\n";
        if (totalRoutes > 0)
        {
            int sum = 0;
            int maxW = 0, minW = INT_MAX;
            for (int i = 0; i < totalRoutes; i++)
            {
                sum += routeWeights[i];
                if (routeWeights[i] > maxW)
                    maxW = routeWeights[i];
                if (routeWeights[i] < minW)
                    minW = routeWeights[i];
            }
            cout << "Average Route Weight: " << (sum / totalRoutes) << "\n";
            cout << "Maximum Route Weight: " << maxW << "\n";
            cout << "Minimum Route Weight: " << minW << "\n";
        }
        cout << "Route analysis based on graph edge weights\n";
        cout << "Higher weight = More traffic/Busier route\n";
        cout << "===================================\n";
    }

    // 3. Fastest Vehicle Assignment (Min-Heap)
    void assignFastestVehicle(MinHeap &vehicleHeap)
    {
        cout << "\n=== Fastest Vehicle Assignment ===\n";
        if (vehicleHeap.isEmpty())
        {
            cout << "No vehicles available.\n";
            return;
        }

        HeapNode fastest = vehicleHeap.getMin();
        cout << "Fastest Vehicle Assigned:\n";
        cout << "  Vehicle ID: " << fastest.id << "\n";
        cout << "  Type: " << fastest.data << "\n";
        cout << "  Priority (Speed): " << fastest.priority << "\n";
        cout << "Using: Min-Heap (Priority Queue)\n";
        cout << "==================================\n";
    }

    // 4. Traffic Density Prediction (Heap Sorting)
    void predictTrafficDensity(MinHeap &trafficHeap)
    {
        cout << "\n=== Traffic Density Prediction ===\n";
        cout << "Predicting traffic density using heap sorting...\n";

        if (trafficHeap.isEmpty())
        {
            cout << "No traffic data available.\n";
            cout << "Add traffic data using Heap menu (option 22).\n";
            return;
        }

        // Display sorted traffic densities without modifying original heap
        // Store all nodes first, then restore
        HeapNode nodes[100];
        int count = 0;
        MinHeap tempHeap(100);

        // Extract all nodes
        while (!trafficHeap.isEmpty() && count < 100)
        {
            nodes[count] = trafficHeap.extractMin();
            tempHeap.insert(nodes[count].priority, nodes[count].data, nodes[count].id);
            count++;
        }

        // Restore original heap
        while (!tempHeap.isEmpty())
        {
            HeapNode node = tempHeap.extractMin();
            trafficHeap.insert(node.priority, node.data, node.id);
        }

        // Display sorted results
        cout << "Traffic Density (Sorted by Priority - Lower = Denser):\n";
        for (int i = 0; i < count; i++)
        {
            cout << "  Rank " << (i + 1) << ": Area " << nodes[i].id
                 << " - Density: " << nodes[i].priority
                 << " (" << nodes[i].data << ")\n";
        }
        cout << "Using: Heap Sorting Algorithm\n";
        cout << "===================================\n";
    }

    // 5. Daily Usage Trends (BST Traversal)
    void analyzeDailyUsageTrends(BST &usageBST)
    {
        cout << "\n=== Daily Usage Trends Analysis ===\n";
        cout << "Analyzing usage trends using BST traversal...\n";
        cout << "In-Order Traversal (Chronological Order):\n";
        usageBST.inOrder();
        cout << "\nBST Traversal provides chronological trend analysis\n";
        cout << "Using: Binary Search Tree Traversal\n";
        cout << "====================================\n";
    }

    // Additional: Generate comprehensive analytics report
    void generateReport(CityGraph &city, MinHeap &vehicleHeap, BST &usageBST)
    {
        cout << "\n========================================\n";
        cout << "   COMPREHENSIVE ANALYTICS REPORT\n";
        cout << "========================================\n\n";

        findMostCrowdedStation(city);
        cout << "\n";
        assignFastestVehicle(vehicleHeap);
        cout << "\n";
        analyzeDailyUsageTrends(usageBST);
        cout << "\n";
        findBusiestRoute(city);
        cout << "\n========================================\n";
    }
};

#endif // ANALYTICS_H
