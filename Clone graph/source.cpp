/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

dfs(node);

*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }  
        std::queue<Node*> nodeQ;
		    std::unordered_map<int, Node*> map;
        std::unordered_set<Node*> visited;
        nodeQ.push(node);
        visited.insert(node);
        Node* gRef = new Node(node->val);
		    Node* ref;
		    Node* nref;
		    map[gRef->val] = gRef;
        while (!nodeQ.empty()) {
			    Node* node = nodeQ.front(); 
			    nodeQ.pop();                
		  	  map.find(node->val) == map.end() ? ref = new Node(node->val) : ref = map[node->val];    // Check if the node is already created in copy graph   
			    map[ref->val] = ref;    // mapping value of node to node
			    for (int i = 0; i < node->neighbors.size(); i++) {
				    Node* neighbor = node->neighbors[i]; 
            map.find(neighbor->val) == map.end() ? nref = new Node(neighbor->val) : nref = map[neighbor->val]; // Checking if the neighbor of node exists in the copygraph already
				    map[nref->val] = nref; 
				    ref->neighbors.push_back(nref);
				    if (visited.find(neighbor) == visited.end()) {
              visited.insert(neighbor);
              nodeQ.push(neighbor);
				    }	
			    }
		    }
       return gRef;
    }
};
