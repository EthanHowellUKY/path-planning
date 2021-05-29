
#ifndef PLANNER_H
#define PLANNER_H

#define ROTATION_LIMIT_DEG 45
#define MAXITER 5000;
#define MAXSTEP_M 1;

#include <vector>
#include <functional>
#include "Graph/Node.h"

class Planner
{
public:
    virtual std::vector<Node> get_path(const Node &start, const Node &goal);

private:
    virtual double cost();
};

#endif // PLANNER_H
