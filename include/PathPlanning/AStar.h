
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
	std::deque<std::shared_ptr<Node> > get_path(std::shared_ptr<Node> &start, std::shared_ptr<Node> &goal) override;
	void print_path(std::deque<std::shared_ptr<Node> > &path) override;

private:
	// -------------------------------- //
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
	double cost(Matrix &mat) override;
	double cost(std::shared_ptr<Node> &parent, std::shared_ptr<Node> &child) override;
	Node get_current();
	std::deque<std::shared_ptr<Node> > build_path(std::vector<std::shared_ptr<Node> > &visited, std::shared_ptr<Node> &current);

	// -------------------------------- //
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
	
};

#endif // ASTAR_H
