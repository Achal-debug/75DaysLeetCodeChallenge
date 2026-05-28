// Day 79 - 100 Days LeetCode Challenge
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        if(mp.find(node) != mp.end()){
            return mp[node];
        }
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(Node* neighbor : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};