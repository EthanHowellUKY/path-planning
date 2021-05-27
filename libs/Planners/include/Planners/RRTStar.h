
#ifndef RRTSTAR_H
#define RRTSTAR_H

#define MAXITER     5000
#define MAXSTEP_M   1

#include <vector>
#include "PathPlanning/Matrix.h"
#include "Planners/Planner.h"

class RRTSTAR : public Planner
{
public:
    // -------------------------------- // 
	//           CONSTRUCTORS           //
	// -------------------------------- //
    RRTSTAR() {}

    // -------------------------------- // 
	//            DESTRUCTOR            //
	// -------------------------------- //
    ~RRTSTAR() {}

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

#endif // RRTSTAR_H
