#pragma once

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

	// Returns if node has been expanded
	bool isExpanded();
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
#pragma endregion

private:
	NodeType tileType;
	Position pos;
	Node* up = nullptr;
	Node* right = nullptr;
	Node* down = nullptr;
	Node* left = nullptr;
	Node* upleft = nullptr;
	Node* upright = nullptr;
	Node* downleft = nullptr;
	Node* downright = nullptr;
	bool expanded = false;
};

