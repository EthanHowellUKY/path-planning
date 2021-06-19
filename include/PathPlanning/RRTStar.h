
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
	std::deque<std::shared_ptr<Node> > get_path(std::shared_ptr<Node> &start, std::shared_ptr<Node> &goal) override;
	void print_path(std::deque<std::shared_ptr<Node> > &path) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost(Matrix &mat) override;
	double cost(std::shared_ptr<Node> &parent, std::shared_ptr<Node> &child) override;

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
};

#endif // RRTSTAR_H
