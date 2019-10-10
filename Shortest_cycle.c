// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define N 100200 
  
vector<int> gr[N]; 
  
// Function to add edge 
void Add_edge(int x, int y) 
{ 
    gr[x].push_back(y); 
    gr[y].push_back(x); 
} 
  
// Function to find the length of 
// the shortest cycle in the graph 
int shortest_cycle(int n) 
{ 
    // To store length of the shortest cycle 
    int ans = INT_MAX; 
  
    // For all vertices 
    for (int i = 0; i < n; i++) { 
  
        // Make distance maximum 
        vector<int> dist(n, (int)(1e9)); 
  
        // Take a imaginary parent 
        vector<int> par(n, -1); 
  
        // Distance of source to source is 0 
        dist[i] = 0; 
        queue<int> q; 
  
        // Push the source element 
        q.push(i); 
  
        // Continue until queue is not empty 
        while (!q.empty()) { 
  
            // Take the first element 
            int x = q.front(); 
            q.pop(); 
  
            // Traverse for all it's childs 
            for (int child : gr[x]) { 
  
                // If it is not visited yet 
                if (dist[child] == (int)(1e9)) { 
  
                    // Increase distance by 1 
                    dist[child] = 1 + dist[x]; 
  
                    // Change parent 
                    par[child] = x; 
  
                    // Push into the queue 
                    q.push(child); 
                } 
  
                // If it is already visited 
                else if (par[x] != child and par[child] != x) 
                    ans = min(ans, dist[x] + dist[child] + 1); 
            } 
        } 
    } 
  
    // If graph contains no cycle 
    if (ans == INT_MAX) 
        return -1; 
  
    // If graph contains cycle 
    else
        return ans; 
} 
  
// Driver code 
int main() 
{ 
    // Number of vertices 
    int n = 7; 
  
    // Add edges 
    Add_edge(0, 6); 
    Add_edge(0, 5); 
    Add_edge(5, 1); 
    Add_edge(1, 6); 
    Add_edge(2, 6); 
    Add_edge(2, 3); 
    Add_edge(3, 4); 
    Add_edge(4, 1); 
  
    // Function call 
    cout << shortest_cycle(n); 
  
    return 0; 
} 