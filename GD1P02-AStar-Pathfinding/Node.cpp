#include "Node.h"

Node::Node()
{
}

Node::~Node()
{
}

Position Node::getPos()
{
    return pos;
}

NodeType Node::getTileType()
{
    return tileType;
}

Neighbors Node::getNeighbors()
{
    return neighbors;
}

void Node::setPos(int _x, int _y)
{
    pos.x = _x;
    pos.y = _y;
}

void Node::setX(int _x)
{
    pos.x = _x;
}

void Node::setY(int _y)
{
    pos.y = _y;
}

void Node::setTileType(NodeType _type)
{
    tileType = _type;
}

void Node::setLeft(Node* _node)
{
    neighbors.left = _node;
}

void Node::setRight(Node* _node)
{
    neighbors.right = _node;
}

void Node::setUp(Node* _node)
{
    neighbors.up = _node;
}

void Node::setDown(Node* _node)
{
    neighbors.down = _node;
}

void Node::setUpLeft(Node* _node)
{
    neighbors.upleft = _node;
}

void Node::setUpRight(Node* _node)
{
    neighbors.upright = _node;
}

void Node::setDownLeft(Node* _node)
{
    neighbors.downleft = _node;
}

void Node::setDownRight(Node* _node)
{
    neighbors.downright = _node;
}
