#include "Node.h"

Node::Node()
{
    this->bound = 0;
    this->level = 0;
}

Node::Node(int b, int l)
{
    this->bound = b;
    this->level = l;
}


Node::~Node()
{
    this->path.clear();
}

