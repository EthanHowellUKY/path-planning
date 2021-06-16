
#include "PathPlanning/AStar.h"

double AStar::cost(Node &parent, Node &child) { return Matrix::norm2(parent * child); }

std::deque<Node> AStar::build_path(std::vector<Node> &visited, Node &current)
{
    std::deque<Node> path{current};
    std::vector<Node>::iterator itr;
    while ((itr = std::find(visited.begin(), visited.end(), current)) != visited.end())
    {
        current = itr->parent();
        path.push_front(current);
    }
    return path;
}

std::deque<Node> AStar::get_path(const Node &start, const Node &goal)
{
    double cost = __FLT_MAX__, min_cost = __FLT_MAX__, total_cost = __FLT_MAX__, est_cost = __FLT_MAX__;
    std::vector<Node> to_explore{start}, visited, edges;
    std::deque<Node> path;
    std::vector<Node>::iterator itr;
    Node current_node;
    int curr_idx, ii;

    while (!to_explore.empty() && ii < MAXITER)
    {
        curr_idx = 0;
        current_node = to_explore[curr_idx];
        for (ii = 0; ii<to_explore.size(); ii++)
        {
            if (to_explore[ii].f < current_node.f)
            {
                curr_idx = ii;
                current_node = to_explore[curr_idx];
            }
        }
        if (current_node == goal)
        {
            std::cout << "Solution found in " << ii << " iterations" << '\n';
            return build_path(visited, current_node);
        }
        else
        {
            itr = std::find(to_explore.begin(), to_explore.end(), current_node);
            visited.push_back(current_node);
            to_explore.erase(itr);

            for (int ii=0; ii < current_node.num_edges(); ii++)
            {
                if (current_node[ii]->dir != DIRECTION::INCOMING)
                {
                    Node *child = current_node[ii]->dest;
                    itr = std::find(visited.begin(), visited.end(), *child);
                    est_cost = current_node.g + this->cost(current_node, *child);
                    if (est_cost < child->g)
                    {
                        child->set_parent(current_node);
                        child->g = est_cost;
                        child->f = child->g + child->pose().trace();
                        if (itr == visited.end()) { visited.push_back(*child); }
                    }
                }
            }
        }

        ii++;
    }
    std::cout << "Taking too long... Exiting" << '\n';

    return path;
}

void AStar::print_path(std::deque<Node> &path) {}
