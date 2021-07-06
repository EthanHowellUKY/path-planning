
#include "PathPlanning/RRTStar.h"

double RRTStar::dRand() { return (double)rand() / MAXSTEP_M; }

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

Node* RRTStar::get_random_node()
{
    return new Node();
}

void RRTStar::print_path(std::deque<Node *> &path) {}
