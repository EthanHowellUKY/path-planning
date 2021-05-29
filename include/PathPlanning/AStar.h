
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
	std::vector<Node> get_path(const Node &start, const Node &goal) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost() override;

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
};

#endif // ASTAR_H
