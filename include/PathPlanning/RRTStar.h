
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

#endif // RRTSTAR_H
