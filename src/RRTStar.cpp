
#include "PathPlanning/RRTStar.h"

double RRTStar::cost(Matrix &mat) { return 0.0; }

double RRTStar::cost(std::shared_ptr<Node> &parent, std::shared_ptr<Node> &child)
{
    return 0.0;
}

std::deque<std::shared_ptr<Node> > RRTStar::get_path(std::shared_ptr<Node> &start, std::shared_ptr<Node> &goal)
{
    std::deque<std::shared_ptr<Node> > path;

    return path;
}

void RRTStar::print_path(std::deque<std::shared_ptr<Node> > &path) {}
