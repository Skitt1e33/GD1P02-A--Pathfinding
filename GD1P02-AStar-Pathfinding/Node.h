#pragma once
#include <Windows.h>

// Type of node instantiated as.
enum NodeType
{
	WALL,
	CLEAR,
	EXIT,
	ENTRANCE,
	ITEM,
	PATH
};

struct Position
{
	int x = 0;
	int y = 0;
};

class Node
{
public:
	Node();
	~Node();

#pragma region Getters
	// Returns x and y position in a position struct.
	//@return Position struct containing x and y position of node.
	Position getPos();

	// Returns tile type.
	NodeType getTileType();

	// Returns upper neighbor node.
	Node* getUp();

	// Returns lower neighbor node.
	Node* getDown();

	// Returns left neighbor node.
	Node* getLeft();

	// Returns right neighbor node.
	Node* getRight();

	// Returns upper right neighbor node.
	Node* getUpRight();

	// Returns lower left neighbor node.
	Node* getDownLeft();

	// Returns upper left neighbor node.
	Node* getUpLeft();

	// Returns lower right neighbor node.
	Node* getDownRight();

	// Returns neighbor node based on given index
	//@param _index: 0 -> up, 2 -> right, 4 -> down, 6 -> left
	Node* getNeighbor(int _index);

	// Returns if node has been expanded
	bool isExpanded();

	// Returns print character
	char getChar();

	// Returns manhattan distance between this node and exit node.
	float getH();

	// Gets and sets total path cost
	//@brief adds distance fromnode to exit to given base distance.
	float getF();

	float getG();

	Node* getPrevPath();
#pragma endregion

#pragma region Setters
	// Set x and y position.
	//@brief Overrides previous location.
	void setPos(int _x, int _y);

	// Set x for node.
	void setX(int _x);

	// Set y for node.
	void setY(int _y);

	// Sets tile type for node.
	void setTileType(NodeType _type);

	// Sets left neighbor to given node pointer
	void setLeft(Node* _node);

	// Sets right neighbor to given node pointer
	void setRight(Node* _node);

	// Sets upper neighbor to given node pointer
	void setUp(Node* _node);

	// Sets lower neighbor to given node pointer
	void setDown(Node* _node);


	// Sets upper left neighbor to given node pointer
	void setUpLeft(Node* _node);

	// Sets upper right neighbor to given node pointer
	void setUpRight(Node* _node);

	// Sets lower left neighbor to given node pointer
	void setDownLeft(Node* _node);

	// Sets lower right neighbor to given node pointer
	void setDownRight(Node* _node);

	// Marks node as expanded
	void expand();

	// Marks node as unexpanded
	void resetNode();

	// Sets print character
	void setChar(char _print);

	// Sets manhattan distance to a given target tile
	void calcDistance(Node* _target);

	void setG(float _value);

	void setPrevPath(Node* _path);
#pragma endregion

	bool operator < (const Node* _node) const
	{
		return f < _node->f;
	}

	float h = 0;
	float f = 0;
	float g = 0;

private:
	NodeType tileType;
	Position pos;
	Node* neighbors[8] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
	Node* prevPath = nullptr;
	char printChar = '.';
	bool expanded = false;

};

