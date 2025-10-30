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
    return neighbors[0];
}

Node* Node::getDown()
{
    return neighbors[4];
}

Node* Node::getLeft()
{
    return neighbors[6];
}

Node* Node::getRight()
{
    return neighbors[2];
}

Node* Node::getUpRight()
{
    return neighbors[1];
}

Node* Node::getDownLeft()
{
    return neighbors[3];
}

Node* Node::getUpLeft()
{
    return neighbors[7];
}

Node* Node::getDownRight()
{
    return neighbors[5];
}

Node* Node::getNeighbor(int _index)
{
    return neighbors[_index];
}

bool Node::isExpanded()
{
    return expanded;
}

char Node::getChar()
{
    return printChar;
}

float Node::getH()
{
    return h;
}

float Node::getF()
{
    return f;
}

float Node::getG()
{
    return g;
}

Node* Node::getPrevPath()
{
    return prevPath;
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
    neighbors[6] = _node;
}

void Node::setRight(Node* _node)
{
    neighbors[2] = _node;
}

void Node::setUp(Node* _node)
{
    neighbors[0] = _node;
}

void Node::setDown(Node* _node)
{
    neighbors[4] = _node;
}

void Node::setUpLeft(Node* _node)
{
    neighbors[7] = _node;
}

void Node::setUpRight(Node* _node)
{
    neighbors[1] = _node;
}

void Node::setDownLeft(Node* _node)
{
    neighbors[5] = _node;
}

void Node::setDownRight(Node* _node)
{
    neighbors[3] = _node;
}

void Node::expand()
{
    expanded = true;
}

void Node::resetNode()
{
    expanded = false;
}

void Node::setChar(char _print)
{
    printChar = _print;
}

void Node::calcDistance(Node* _target)
{
    h = abs(_target->getPos().x - pos.x) + abs(_target->getPos().y - pos.y);
    f = g + h;
}

void Node::setG(float _value)
{
    g = _value;
    f = g + h;
}

void Node::setPrevPath(Node* _path)
{
    prevPath = _path;
}
