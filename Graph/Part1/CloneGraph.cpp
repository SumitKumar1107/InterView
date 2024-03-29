Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

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
*/

class Solution {
public:
    //https://www.youtube.com/watch?v=f2EfGComRKM&t=653s
    void dfs(Node*curr, Node*node,vector<Node *>& visited)
    {
        visited[node->val] = node;
        for(auto ele:curr->neighbors)
        {
            if(visited[ele->val]==NULL)
            {
                Node* newnode = new Node(ele->val);
                (node->neighbors).push_back(newnode);
                dfs(ele,newnode,visited); 
            }
            else
            {
                (node->neighbors).push_back(visited[ele->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
        return NULL;
        
        vector<Node*>visited(1000,NULL);
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        
        for(auto curr : node->neighbors)
        {
            if(visited[curr->val]==NULL)
            {
                Node* newnode = new Node(curr->val);
                copy->neighbors.push_back(newnode);
                dfs(curr,newnode,visited);
            }
            else
               (copy->neighbors).push_back(visited[curr->val]); 
        }
        return copy;
    }
};