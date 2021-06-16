
#ifndef PLANNER_H
#define PLANNER_H

#define ROTATION_LIMIT_DEG 45
#define MAXITER 5000
#define MAXSTEP_M 1

#include <map>
#include <deque>
#include <vector>
#include <functional>
#include "Graph/Node.h"

class Planner
{
public:
    virtual std::deque<Node> get_path(const Node &start, const Node &goal);
    virtual void print_path(std::deque<Node> &path);

private:
    virtual double cost(Node &parent, Node &child);
};

#endif // PLANNER_H
