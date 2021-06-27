
#ifndef ASTAR_H
#define ASTAR_H

#include "PathPlanning/Planner.h"

struct NodeComparator
{
	bool operator()(const Node *lhs, const Node *rhs) const
	{
		return lhs->f > rhs->f;
	}
};

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
	std::deque<Node *> get_path(Node *start, Node *goal) override;
	void print_path(std::deque<Node *> &path) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost(Node *parent, Node *child) override;
	std::deque<Node *> build_path(std::vector<Node *> &visited, Node *current) override;

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
	
};

#endif // ASTAR_H
