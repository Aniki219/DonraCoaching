#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void DFSIteration(map<int, set<int>> graph) {
    stack<int> stk;
    cout << 1 << " ";
    stk.push(1);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        for (set<int>::iterator i = graph[current].begin(); i != graph[current].end(); i++) {
            cout << *i << " ";
            stk.push(*i);
        }
    }
}

void DFS(map<int, set<int>> graph, int current) {
    static set<int> visited;

    visited.insert(current);
    cout << current << " ";
    for (set<int>::iterator i = graph[current].begin(); i != graph[current].end(); i++) {
        if (!visited.count(*i)) {
            DFS(graph, *i);
        }
    }
    return;
}

void BFS(map<int, set<int>> graph, int start) {
    set<int> visited;
    queue<int> children; 
    children.push(start);

    while(!children.empty()) {
        int current = children.front();
        children.pop();

        cout << current << " ";
        visited.insert(current);

        for (set<int>::iterator i = graph[current].begin(); i != graph[current].end(); i++) {
            if (!visited.count(*i)) {
                children.push(*i);
            }
        }
    }

    return;
}

int main() {
    map<int, set<int>> graph;
    graph.insert(make_pair(1, set<int>{2, 3}));
    graph.insert(make_pair(2, set<int>{4, 5}));
    graph.insert(make_pair(3, set<int>{6, 7}));
    graph.insert(make_pair(4, set<int>()));
    graph.insert(make_pair(5, set<int>()));
    graph.insert(make_pair(6, set<int>()));
    graph.insert(make_pair(7, set<int>{5}));

    cout << "DFS: " << endl;
    DFS(graph, 1);
    cout << endl << "BFS: " << endl;
    BFS(graph, 1);
    return 0;
}