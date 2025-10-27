#include "Graph.h"

void setColour(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::loadMap(std::string _filepath)
{
    std::string line;
    std::ifstream levelFile;
    levelFile.open("ExampleMaps/" + _filepath);

    if (!levelFile.is_open()) return;

    int y = 0;
    map* newMap = new map;

    while (!levelFile.eof())
    {
        std::getline(levelFile, line);

        if (line.empty()) continue;

        Node* prevNode = nullptr;

        for (int x = 0; x < int(line.length()); ++x)
        {
            char actorChar = line[x];
            Node* newNode = new Node;
            newNode->setPos(x, y);
            if (prevNode != nullptr)
            {
                newNode->setLeft(prevNode);
                prevNode->setRight(newNode);
            }

            if (y > 0)
            {
                Node* topNode = newMap->nodes[x*(y-1)];
                newNode->setUp(topNode);
                if (topNode->getLeft() != nullptr)
                {
                    newNode->setUpLeft(topNode->getLeft());
                    topNode->getLeft()->setDownRight(newNode);
                }

                if (topNode->getRight() != nullptr)
                {
                    newNode->setUpRight(topNode->getRight());
                    topNode->getRight()->setDownLeft(newNode);
                }
            }

            switch (actorChar)
            {
            // wall
            case 'w':
                newNode->setTileType(WALL);
                newNode->setChar('w');
                break;
                
            // clear
            case '.':
                newNode->setTileType(CLEAR);
                newNode->setChar('.');
                break;

            // start
            case 's':
                newNode->setTileType(ENTRANCE);
                newMap->entranceCount++;
                newNode->setChar('s');
                break;

            // destination
            case 'x':
                newNode->setTileType(EXIT);
                newMap->exitCount++;
                newNode->setChar('x');
                break;

            default:
                newNode->setTileType(ITEM);
                newNode->setChar(97 + newMap->itemCount);
                newMap->itemCount++;
                break;
            }

            prevNode = newNode;
            newMap->nodes.push_back(newNode);
        }
        y++;
    }

    levels.push_back(newMap);

    levelFile.close();

    setColour(7, 0);
    std::cout << "Map Loaded Successfully" << std::endl;

    setColour(4, 0);
    if (newMap->entranceCount > 1 || newMap->exitCount > 1)
    {
        std::cout << "Invalid Map: too many entrances/exits" << std::endl;
    }

    if (newMap->entranceCount < 1 || newMap->exitCount < 1)
    {
        std::cout << "Invalid Map: missing entrance/exit" << std::endl;
    }
}

void Graph::printMap(int _index)
{
    if (_index < 0 || _index > levels.size()-1)
    {
        std::cout << "index out of range" << std::endl;
        return;
    }
    map level = *levels[_index];

    int y = 0;

    for (int i = 0; i < level.nodes.size(); ++i)
    {
        switch (level.nodes[i]->getTileType())
        {
        case CLEAR:
            setColour(7, 0);
            break;

        case ENTRANCE:
            setColour(2, 0);
            break;

        case EXIT:
            setColour(12, 0);
            break;

        case WALL:
            setColour(3, 0);
            break;

        case ITEM:
            setColour(6, 0);
            break;

        case PATH:
            setColour(6, 0);
            break;
        }

        if (level.nodes[i]->getPos().y > y)
        {
            ++y;
            std::cout << std::endl;
        }
        std::cout << level.nodes[i]->getChar() << " ";
    }

    std::cout << std::endl;
    setColour(7,0);
}

void Graph::unload(int _index)
{
    for (int i = 0; i < levels[_index]->nodes.size(); ++i)
    {
        delete levels[_index]->nodes[i];
    }
    levels[_index]->nodes.clear();
}

void Graph::depthFirst(int _index)
{
    std::vector<Node*> itemList;
    getItems(itemList, _index);

    std::cout << "visit order: ";
    dFSRecursion(itemList, 0);

    for (int i = 0; i < itemList.size(); ++i)
    {
        itemList[i]->resetNode();
    }
}

void Graph::dFSRecursion(std::vector<Node*>& _graph, int _index)
{
    _graph[_index]->expand();
    std::cout << _graph[_index]->getChar() << ", ";
    Node* node = _graph[_index];
    _graph.erase(_graph.begin()+_index);

    int closestNode = 0;
    float closestDist = FLT_MAX;

    for (int j = 0; j < _graph.size(); ++j)
    {
        if (getDistance(node, _graph[j]) < closestDist)
        {
            closestNode = j;
            closestDist = getDistance(node, _graph[j]);
        }
    }

    for (int i = 0; i < _graph.size(); ++i)
    {
        dFSRecursion(_graph, closestNode);
    }
}

float Graph::getDistance(Node* _n1, Node* _n2)
{
    float x = _n2->getPos().x - _n1->getPos().x;
    float y = _n2->getPos().y - _n1->getPos().y;

    return sqrt(pow(x,2)+pow(y,2));
}

void Graph::getItems(std::vector<Node*>& _itemList, int _index)
{
    map level = *levels[_index];
    for (int i = 0; i < level.nodes.size(); ++i)
    {
        if (level.nodes[i]->getTileType() == ITEM) _itemList.push_back(level.nodes[i]);
    }
}
