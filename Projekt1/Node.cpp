#include "Node.h"

Node::Node()
{
    this->bound = 0;
    this->value = 0;
    this->level = 0;
}

Node::Node(int b, int v, int l)
{
    this->bound = b;
    this->value = v;
    this->level = l;
}


Node::~Node()
{
}

