
#include "PathPlanning/AStar.h"

double AStar::cost(Node *parent, Node *child) { return (parent->pose() * child->pose()).norm(); }

std::deque<Node *> AStar::build_path(std::vector<Node *> &visited, Node *current)
{
    std::deque<Node *> path{current};
    std::vector<Node *>::iterator itr;
    while ((itr = std::find(visited.begin(), visited.end(), current)) != visited.end() && (*itr)->has_parent)
    {
        current = (*itr)->parent();
        path.push_front(current);
    }

    return path;
}

std::deque<Node *> AStar::get_path(Node *start, Node *goal)
{
    double est_cost = __FLT_MAX__;
    start->f = this->cost(start, goal);
    std::priority_queue<Node *, std::vector<Node *>, NodeComparator> to_explore;
    to_explore.push(start);
    std::vector<Node *> visited;
    std::deque<Node *> path;
    std::vector<Node *>::iterator itr;
    Node *current_node;
    int ii, xx=0;

    /*
        Loop over all the nodes until
            1. Each node has been evaluated
            2. A solution has been found
            3. Max iteration limit has been hit.
    */
    while (!to_explore.empty() && xx < MAXITER)
    {
        xx++;

        /*
            Assign the "current node" as the node who has the lowest total
            "f". This cost is a summation of the costs at each node prior
            to this node, and the distance from the current node to the
            goal node.
        */
        current_node = to_explore.top();
        
        /*
            Check to see if the lowest cost node to evaluate is the goal node.
            If it is, build the path from finish to start via the assigned
            "parent" node.
        */
        if (current_node == goal)
        {
            std::cout << "Solution found in " << xx << " iterations" << '\n';
            return build_path(visited, current_node);
        }
        else
        {
            to_explore.pop(); // Remove the current node from the exploration list.
            visited.push_back(current_node); // Add the current node to the vector of visited nodes.

            /*
                Evaluate each of the current nodes edges to try and find a
                better path than the one currently assigned.
            */
            for (int jj=0; jj < current_node->num_edges(); jj++)
            {
                Edge* current_edge = current_node->get_edge(jj);

                // Verify that the directed edge allows the movement.
                if (current_edge->dir != DIRECTION::INCOMING)
                {
                    Node *child = current_edge->dest;
                    itr = std::find(visited.begin(), visited.end(), child);
                    double distance = this->cost(current_node, child);
                    est_cost = current_node->g + distance;

                    // Check to see if the cost of this move is better than any previous move.
                    if (est_cost < child->g)
                    {
                        child->set_parent(current_node);
                        child->g = est_cost;
                        child->f = child->g + this->cost(child, goal);
                        if (itr == visited.end()) { visited.push_back(child); }
                        to_explore.push(child);
                    }
                }
            }
        }
    }
    std::cout << "Taking too long... Exiting: " << xx << '\n';

    return path;
}

void AStar::print_path(std::deque<Node *> &path)
{
    for (int ii = 0; ii<path.size(); ii++)
    {
        Node *current_node = path[ii];
        std::cout << current_node->name();
        if (ii != path.size()-1)
        {
            std::cout << " -> ";
        }
    }
    std::cout << '\n';
}
