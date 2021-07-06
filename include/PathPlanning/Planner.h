
#ifndef PLANNER_H
#define PLANNER_H

#define ROTATION_LIMIT_DEG 45
#define MAXITER 5000
#define MAXSTEP_M 1

#include <map>
#include <set>
#include <deque>
#include <queue>
#include <vector>
#include <functional>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Graph/Node.h"

class Planner
{
public:
    virtual std::deque<Node *> get_path(Node *start, Node *goal) = 0;
    virtual void print_path(std::deque<Node *> &path) = 0;

private:
    virtual double cost(Node *parent, Node *child) = 0;
    virtual std::deque<Node *> build_path(std::vector<Node *> &visited, Node *current) = 0;
};

#endif // PLANNER_H
