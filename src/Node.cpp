
#include "PathPlanning/Node.h"

// -------------------------------- // 
//        PRIVATE FUNCTIONS         //
// -------------------------------- //

// -------------------------------- // 
//           CONSTRUCTORS           //
// -------------------------------- //
Node::Node(const std::vector<float> &origin)
    : m_pose(origin.size()+1, origin.size()+1)
{
}

Node::Node(const std::vector<float> &origin, const Matrix &orientation)
    : m_pose(origin.size()+1, origin.size()+1)
{
}

Node::Node(const Matrix &pose) { m_pose = pose; }

// -------------------------------- // 
//            DESTRUCTOR            //
// -------------------------------- //
Node::~Node() {}

// -------------------------------- // 
//            OPERATORS             //
// -------------------------------- //
bool Node::operator==(const Node &rhs) const { return m_pose == rhs.pose(); }

// -------------------------------- // 
//         PUBLIC FUNCTIONS         //
// -------------------------------- //
void Node::add_neighbor(const Node &neighbor, DIRECTIONS &direction) {  }
Matrix Node::pose() const { return m_pose; }
