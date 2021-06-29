
#include "Graph/Node.h"

// -------------------------------- //
//        PRIVATE FUNCTIONS         //
// -------------------------------- //
Edge* Node::get_edge() { return new Edge(); }

// -------------------------------- //
//           CONSTRUCTORS           //
// -------------------------------- //
Node::Node(const int &id, const std::string &name, const std::vector<float> &origin)
    : m_pose(origin.size() + 1, origin.size() + 1),
      m_name{name},
      m_id{id}
{
    has_parent = false;

    int col = origin.size() - 1;
    for (int ii = 0; ii < origin.size(); ii++)
    {
        m_pose(ii, col) = origin[ii];
    }
    m_pose(col, col) = 1;
}

Node::Node(const int &id, const std::string &name, const std::vector<float> &origin, const Matrix &orientation)
    : m_pose(origin.size() + 1, origin.size() + 1),
      m_name{name},
      m_id{id}
{
    has_parent = false;
    for (int ii = 0; ii < orientation.rows() + 1; ii++)
    {
        for (int jj = 0; jj < orientation.cols() + 1; jj++)
        {
            if (ii == orientation.rows() && jj == orientation.cols()) { m_pose(ii, jj) = 1; }
            else if (jj == orientation.cols()) { m_pose(ii, jj) = origin[jj]; }
            else { m_pose(ii, jj) = orientation(ii, jj); }
        }
    }
}

Node::Node(const int &id, const std::string &name, const Matrix &pose)
    : m_name{name},
      m_id{id}
{
    has_parent = false;
    m_pose = pose;
}

// -------------------------------- //
//            DESTRUCTOR            //
// -------------------------------- //
Node::~Node() { m_edges.clear(); }

// -------------------------------- //
//            OPERATORS             //
// -------------------------------- //
bool            Node::operator==(const Node &rhs) const { return m_pose == rhs.pose(); }
bool            Node::operator!=(const Node &rhs) const { return !(this->pose() == rhs.pose()); }
Matrix  Node::operator*(const Node &rhs) const { return this->pose() * rhs.pose(); }
Edge*           Node::operator[](const int &idx) { return m_edges[idx]; }

// -------------------------------- //
//         PUBLIC FUNCTIONS         //
// -------------------------------- //
int Node::connects_with(Node *node)
{
    for (int ii = 0; ii < m_edges.size(); ii++)
    {
        if (m_edges[ii]->dest == node)
        {
            return ii;
        }
    }

    return -1;
}

// ------------ GETTERS ----------- //
Edge*           Node::get_edge(const int &idx) { return m_edges[idx]; }
Matrix  Node::pose() const { return m_pose; }
Node*           Node::parent() { return m_parent; }
int             Node::num_edges() const { return m_edges.size(); }
double          Node::cost() const { return m_cost; }
std::string     Node::name() const { return m_name; }
int             Node::id() const { return m_id; }

// ------------ SETTERS ----------- //
void Node::reconfigure_edge(Edge *edge, const DIRECTION &dir, DIRECTION &out_dir)
{
    if (edge->dir == dir || edge->dir == BIDIRECTIONAL)
    {
        edge->dir = BIDIRECTIONAL;
        out_dir = BIDIRECTIONAL;
    }
}

void Node::add_edge(Node *dest, const DIRECTION &dir)
{
    Edge *new_edge = get_edge();
    new_edge->dest = dest;
    m_edges.push_back(new_edge);

    DIRECTION dir_copy = dir;
    int idx;
    
    if ((idx = dest->connects_with(this)) == -1)
    {
        switch (dir)
        {
        case INCOMING:
            dest->add_edge(this, OUTGOING);
            break;
        case OUTGOING:
            dest->add_edge(this, INCOMING);
            break;
        case BIDIRECTIONAL:
            dest->add_edge(this, BIDIRECTIONAL);
            break;
        }
    }
    else
    {
        Edge *neighbor_connection = dest->get_edge(idx);
        switch (neighbor_connection->dir)
        {
        case INCOMING:
            this->reconfigure_edge(neighbor_connection, INCOMING, dir_copy);
            break;
        
        case OUTGOING:
            this->reconfigure_edge(neighbor_connection, OUTGOING, dir_copy);
            break;
        case BIDIRECTIONAL:
            break;
        }
    }

    new_edge->dir = dir_copy;
}

void        Node::set_parent(Node *parent) { has_parent = true; m_parent = parent; }
void        Node::set_cost(const double &cost) { m_cost = cost; }
