
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
	std::deque<Node *> get_path(Node *start, Node *goal) override;
	void print_path(std::deque<Node *> &path) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost(Matrix &mat) override;
	double cost(Node *parent, Node *child) override;
	std::deque<Node *> build_path(std::vector<Node *> &visited, Node *current) override;

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
	
};

#endif // ASTAR_H
