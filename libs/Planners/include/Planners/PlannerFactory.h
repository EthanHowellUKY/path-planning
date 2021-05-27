
#ifndef PLANNERFACTORY_H
#define PLANNERFACTORY_H

#include "Planners/Planner.h"
#include "Planners/AStar.h"
#include "Planners/RRTStar.h"

enum PATHPLANNER {
    AStar=0,
    RRTStar
};

class PlannerFactory
{
public:
    static Planner create(PATHPLANNER &planner);
};

#endif // PLANNERFACTORY_H
