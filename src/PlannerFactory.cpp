
#include "PathPlanning/PlannerFactory.h"

Planner* PlannerFactory::create(const PATHPLANNER &planner)
{
    switch (planner)
    {
    case ASTAR:
        return new AStar();
        break;
    case RRTSTAR:
        return new RRTStar();
        break;
    default:
        return new AStar();
        break;
    }
}
