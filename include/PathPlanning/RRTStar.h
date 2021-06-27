
#ifndef RRTSTAR_H
#define RRTSTAR_H

#include "PathPlanning/Planner.h"

class RRTStar : public Planner
{
public:
	// -------------------------------- //
	//           CONSTRUCTORS           //
	// -------------------------------- //
	RRTStar() {}

	// -------------------------------- //
	//            DESTRUCTOR            //
	// -------------------------------- //
	~RRTStar() {}

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

#endif // RRTSTAR_H
