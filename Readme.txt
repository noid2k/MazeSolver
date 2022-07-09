This code was written in Visual Studio 19 / c++ 11

to compile please do the following

$ g++ -std=c++11 Project3.cpp -o Project3

The programm will ask you for a file name. Please provide the name of a txt file correct format

Example: tarzan.txt
or
	 small.txt
or
	 large.txt


Since the goal is to find a path, Adjacency matrix would is the perfect representation of a
graph here. Basically, the idea is to store each node in matrix, the connection to the next
node will be represented as the code, for instance, if we have a node with the direction of “S”
it will be connected to the nodes which are x + 3 and x + 4 (lower than current node).


The algorithm I used is DFS with backtracking. Recursively go to the length of
3 first marking all the visited nodes as explored. When I get to a situation where I can’t go
any deeper, I’ll try to go by 4. If there are no options for a step of length 4, I return to the
previous option and try the step of length 4 at this node until I find the node “J”. As I find Jojo,
I will return 1 and start outputting the path. The explored cells I’m going to store in a vector
matrix of the size of the input maze.