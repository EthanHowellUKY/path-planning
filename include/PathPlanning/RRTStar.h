
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
	std::deque<Node> get_path(const Node &start, const Node &goal) override;
	void print_path(std::deque<Node> &path) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost(Node &parent, Node &child) override;

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
};

#endif // RRTSTAR_H
