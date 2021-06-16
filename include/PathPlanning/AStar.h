
#ifndef ASTAR_H
#define ASTAR_H

#include "PathPlanning/Planner.h"

class AStar : public Planner
{
public:
	// -------------------------------- //
	//           CONSTRUCTORS           //
	// -------------------------------- //
	AStar() {}

	// -------------------------------- //
	//            DESTRUCTOR            //
	// -------------------------------- //
	~AStar() {}

	// -------------------------------- //
	//         PUBLIC FUNCTIONS         //
	// -------------------------------- //
	std::deque<Node> get_path(const Node &start, const Node &goal) override;
	void print_path(std::deque<Node> &path) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost(Node &parent, Node &child) override;
	Node get_current();
	std::deque<Node> build_path(std::vector<Node> &visited, Node &current);

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
	
};

#endif // ASTAR_H
