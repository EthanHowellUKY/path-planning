
#include "PathPlanning/PlannerFactory.h"

Planner PlannerFactory::create(PATHPLANNER &planner)
{
    switch (planner)
    {
    case ASTAR:
        return AStar();
        break;
    case RRTSTAR:
        return RRTStar();
        break;
    default:
        return AStar();
        break;
    }
}
