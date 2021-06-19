
#ifndef PLANNER_H
#define PLANNER_H

#define ROTATION_LIMIT_DEG 45
#define MAXITER 5000
#define MAXSTEP_M 1

#include <map>
#include <deque>
#include <vector>
#include <memory>
#include <functional>
#include "Graph/Node.h"

class Planner
{
public:
    virtual std::deque<std::shared_ptr<Node> > get_path(std::shared_ptr<Node> &start, std::shared_ptr<Node> &goal) = 0;
    virtual void print_path(std::deque<std::shared_ptr<Node> > &path) = 0;
    std::map<int, Node> graph;

private:
    virtual double cost(Matrix &mat) = 0;
    virtual double cost(std::shared_ptr<Node> &parent, std::shared_ptr<Node> &child) = 0;
};

#endif // PLANNER_H
