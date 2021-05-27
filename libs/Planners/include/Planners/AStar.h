
#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include "PathPlanning/Matrix.h"
#include "Planners/Planner.h"

class ASTAR : public Planner
{
public:
	// -------------------------------- // 
	//           CONSTRUCTORS           //
	// -------------------------------- //
	ASTAR() {}

	// -------------------------------- // 
	//            DESTRUCTOR            //
	// -------------------------------- //
	~ASTAR() {}

	// -------------------------------- // 
	//         PUBLIC FUNCTIONS         //
	// -------------------------------- //
	std::vector<Matrix> get_path(const Matrix &start, const Matrix &goal) override;

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
