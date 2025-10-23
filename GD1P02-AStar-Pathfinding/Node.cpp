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

Node* Node::getUp()
{
    return up;
}

Node* Node::getDown()
{
    return down;
}

Node* Node::getLeft()
{
    return left;
}

Node* Node::getRight()
{
    return right;
}

Node* Node::getUpRight()
{
    return upright;
}

Node* Node::getDownLeft()
{
    return downleft;
}

Node* Node::getUpLeft()
{
    return upleft;
}

Node* Node::getDownRight()
{
    return downright;
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
    left = _node;
}

void Node::setRight(Node* _node)
{
    right = _node;
}

void Node::setUp(Node* _node)
{
    up = _node;
}

void Node::setDown(Node* _node)
{
    down = _node;
}

void Node::setUpLeft(Node* _node)
{
    upleft = _node;
}

void Node::setUpRight(Node* _node)
{
    upright = _node;
}

void Node::setDownLeft(Node* _node)
{
    downleft = _node;
}

void Node::setDownRight(Node* _node)
{
    downright = _node;
}
