//
// Created by Leo Chen on 2023/10/9.
//


#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class CloneGraph {
private:
    map<Node*, Node*> visited;
public:
    Node *cloneGraph(Node *node) {
        if(node == nullptr){
            return node;
        }

        if(visited.find(node) != visited.end()){
            return visited[node];
        }

        Node *cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for(Node *n : node->neighbors){
            cloneNode->neighbors.push_back(this->cloneGraph(n));
        }
        return cloneNode;
    }
};