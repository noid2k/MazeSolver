// Project3.cpp 
//  Written by Aleksei Khvorostov

#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


struct NodePoint
{
    int x;
    int y;
    char dir;
};

bool isNode(vector<vector<NodePoint>>& maze, vector<vector<bool>>& visited, int x, int y)
{
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size()) && !visited[x][y] && maze[x][y].dir!='X';
}


bool findPathMeme(vector<vector<NodePoint>>& maze, NodePoint position, NodePoint finish, vector<vector<bool>>& visited)
    {
    // Found Jojo
    if (position.dir == 'J')
    {
            cout << position.dir <<" - Yaay we found JOJO\n";
            return 1;
    }
    
    visited[position.x][position.y] = true;
    if (position.dir == 'S')
    {
        if (isNode(maze, visited, position.x + 3, position.y)) {
            position = maze[position.x + 3][position.y];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x - 3][position.y];
                cout << position.dir << "-3\t";
                return 1;
            }
            position = maze[position.x -3][position.y];
        }
        if (isNode(maze, visited, position.x + 4, position.y)) {
            position = maze[position.x + 4][position.y];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x - 4][position.y];
                cout << position.dir << "-4\t";
                return 1;
            }
            position = maze[position.x - 4][position.y];
        }
    }
    if (position.dir == 'W')
    {
        if (isNode(maze, visited, position.x, position.y - 3)) {
            position = maze[position.x][position.y - 3];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x][position.y + 3];
                cout << position.dir << "-3\t";
                return 1;
            }
            position = maze[position.x ][position.y+3];

        }
        if (isNode(maze, visited, position.x, position.y - 4)) {
            position = maze[position.x ][position.y - 4];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x][position.y + 4];
                cout << position.dir << "-4\t";
                return 1;
            }
            position = maze[position.x ][position.y+4];
        }
    }
    if (position.dir == 'N')
    {
        if (isNode(maze, visited, position.x - 3, position.y)) {
            position = maze[position.x - 3][position.y];
            if (findPathMeme(maze, position, finish, visited))
            {

                position = maze[position.x + 3][position.y];
                cout << position.dir << "-3\t";
                return 1;
            }
            position = maze[position.x + 3][position.y];
        }
        if (isNode(maze, visited, position.x - 4, position.y )) {
            position = maze[position.x - 4][position.y ];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x + 4][position.y];
                cout << position.dir << "-4\t";
                return 1;
            }
            position = maze[position.x + 4][position.y];
        }
    }
    if (position.dir == 'E')
    {
        if (isNode(maze, visited, position.x, position.y + 3)) {
            position = maze[position.x][position.y + 3];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x][position.y - 3];
                cout << position.dir << "-3\t";
                return 1;
            }
            position = maze[position.x ][position.y-3];
        }
        if (isNode(maze, visited, position.x, position.y + 4)) {
            position = maze[position.x][position.y + 4];

            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x][position.y - 4];
                cout << position.dir << "-4\t";
                return 1;
            }
            position = maze[position.x ][position.y-4];
        }
    }
    if (position.dir == 'A')
    {
        if (isNode(maze, visited, position.x+3, position.y - 3)) {
            position = maze[position.x + 3][position.y - 3];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x - 3][position.y + 3];
                cout << "SW-3\t";
                return 1;
            }
            position = maze[position.x - 3][position.y + 3];
        }
        if (isNode(maze, visited, position.x+4, position.y - 4)) {
            position = maze[position.x + 4][position.y - 4];

            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x - 4][position.y + 4];
                cout <<"SW-4\t";
                return 1;
            }
            position = maze[position.x - 4][position.y + 4];
        }
    }
    if (position.dir == 'B')
    {
        if (isNode(maze, visited, position.x-3, position.y - 3)) {
            position = maze[position.x-3][position.y - 3];
            if (findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x + 3][position.y + 3];
                cout <<"NW-3\t";
                return 1;
            }
            position = maze[position.x+3][position.y + 3];
        }
        if (isNode(maze, visited, position.x-4, position.y - 4)) {
            position = maze[position.x-4][position.y - 4];

            if(findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x + 4][position.y + 4];
                cout <<"NW-4\t";
                return 1;
            }
            position = maze[position.x+4][position.y +4];
        }
    }
    if (position.dir == 'C')
    {
        if (isNode(maze, visited, position.x+3, position.y + 3)) {
            position = maze[position.x+3][position.y + 3];
            if(findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x - 3][position.y - 3];
                cout << "SE-3\t";
                return 1;
            }
            position = maze[position.x-3][position.y - 3];
        }
        if (isNode(maze, visited, position.x+4, position.y + 4)) {
            position = maze[position.x+4][position.y + 4];

            if(findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x - 4][position.y - 4];
                cout << "SE-4\t";
                return 1;
            }
            position = maze[position.x-4][position.y - 4];
        }
    }
    if (position.dir == 'D')
    {
        if (isNode(maze, visited, position.x-3, position.y + 3)) {
            position = maze[position.x-3][position.y + 3];
            if(findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x + 3][position.y - 3];
                cout <<"NE-3\t";
                return 1;
            }
            position = maze[position.x+3][position.y - 3];
        }
        if (isNode(maze, visited, position.x - 4 , position.y + 4)) {
            position = maze[position.x-4][position.y + 4];

            if(findPathMeme(maze, position, finish, visited))
            {
                position = maze[position.x + 4][position.y - 4];
                cout <<"NE-4\t";
                return 1;
            }
            position = maze[position.x+4][position.y - 4];
        }
    }
 
    visited[position.x][position.y] = false;
    return 0;
}

int findPath(vector<vector<NodePoint>>&maze, NodePoint start, NodePoint finish,int row,int col)
{
    // construct an `M × N` matrix to keep track of visited cells
    vector<vector<bool>> visited;
    visited.resize(row, vector<bool>(col));
    

    if (findPathMeme(maze, start, finish, visited))
        cout << "\nwe found a path to JOJO\n";
    else
        cout << "\nwe couldn't find a path to JOJO\n";
    return -1;
}

int main()
{
    int x;
    
    cout << "Hello, please provide text file name! Example: tarzan.txt\n";
    string name;
    cin >> name;
    ifstream ifs(name); 
    ifs >> x;
    int row = x;
    ifs >> x;
    int col = x;
    ifs >> x;
    int startX = x-1;
    ifs >> x;
    int startY = x-1;
    vector<vector<NodePoint>> maze;
    maze.resize(row, vector<NodePoint>(col));
    string s;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        { 
            ifs >> s;
            if (s == "SW")
                s[0] = 'A';
            if (s == "NW")
                s[0] = 'B';
            if (s == "SE")
                s[0] == 'C';
            if (s == "NE")
                s[0] == 'D';
            maze[i][j] = { i,j,s[0]};
        }

    /*  vector<vector<NodePoint>> maze =
    {
        {{0,0,'S',0}, {1,1,'X',0}, {0,2,'X',0}, {0,3,'X',0}, {0,4,'X',0}},
        {{1,0,'S',0}, {1,1,'X',0}, {1,2,'X',0}, {1,3,'X',0}, {1,4,'X',0}},
        {{2,0,'S',0}, {2,1,'S',0}, {2,2,'S',0}, {2,3,'S',0}, {2,4,'S',0}},
        {{3,0,'E',0}, {3,1,'E',0}, {3,2,'W',0}, {3,3,'W',0}, {3,4,'S',0}},
        {{4,0,'X',0}, {4,1,'X',0}, {4,2,'X',0}, {4,3,'X',0}, {4,4,'S',0}},
        {{5,0,'X',0}, {5,1,'X',0}, {5,2,'X',0}, {5,3,'X',0}, {5,4,'N',0}},
        {{6,0,'X',0}, {6,1,'X',0}, {6,2,'X',0}, {6,3,'X',0}, {6,4,'N',0}},
        {{7,0,'J',0}, {7,1,'E',0}, {7,2,'E',0}, {7,3,'X',0}, {7,4,'W',0}},
    };*/
    
    NodePoint start = maze[startX][startY];
    NodePoint finish;
    finish.dir = 'J';
    findPath(maze, start, finish,row,col);

    return 0;
}

