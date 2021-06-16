
#include "PathPlanning/RRTStar.h"

double RRTStar::cost(Node &parent, Node &cost)
{
    return 0.0;
}

std::deque<Node> RRTStar::get_path(const Node &start, const Node &goal)
{
    std::deque<Node> path;

    return path;
}

void RRTStar::print_path(std::deque<Node> &path) {}
