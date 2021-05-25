
#include "PathPlanning/PlannerFactory.h"

Planner PlannerFactory::create(PATHPLANNER &planner)
{
    switch (planner)
    {
        case AStar:
            return ASTAR();
            break;
        case RRTStar:
            return RRTSTAR();
            break;
        default:
            return ASTAR();
            break;
    }
}
