
#include "PathPlanning/RRTStar.h"

double RRTStar::cost(Matrix &mat) { return 0.0; }

std::deque<Node *> RRTStar::build_path(std::vector<Node *> &visited, Node *current)
{
    std::deque<Node *> path;
    return path;
}

double RRTStar::cost(Node *parent, Node *child)
{
    return 0.0;
}

std::deque<Node *> RRTStar::get_path(Node *start, Node *goal)
{
    std::deque<Node *> path;

    return path;
}

void RRTStar::print_path(std::deque<Node *> &path) {}
