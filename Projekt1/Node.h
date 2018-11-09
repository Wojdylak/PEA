#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
public:
    int level;
    int bound;
    int value;
    
    std::vector <int> path;
    
    Node();
    Node(int b, int v, int l);
    ~Node();
};

struct comp{
    bool operator()(const Node& a, const Node& b) const
    {
        return a.bound > b.bound;
    }
};

#endif // NODE_H