
#ifndef NODE_H
#define NODE_H

#include "PathPlanning/Matrix.h"
#include <vector>
#include <map>
#include <math.h>

enum DIRECTIONS {
    INCOMING=-1,
    BIDIRECTIONAL,
    OUTGOING
};

class Node
{
public:
    // -------------------------------- // 
	//           CONSTRUCTORS           //
	// -------------------------------- //
    Node(const std::vector<float> &origin);
    Node(const std::vector<float> &origin, const Matrix &orientation);
    Node(const Matrix &pose);

    // -------------------------------- // 
	//            DESTRUCTOR            //
	// -------------------------------- //
    ~Node();

    // -------------------------------- // 
	//            OPERATORS             //
	// -------------------------------- //
    bool operator==(const Node &rhs) const;

    // -------------------------------- // 
	//         PUBLIC FUNCTIONS         //
	// -------------------------------- //
    void add_neighbor(const Node &neighbor, DIRECTIONS &direction);
    Matrix pose() const;

private:
    // -------------------------------- // 
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //

    // -------------------------------- // 
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
    Matrix m_pose;
};

#endif // NODE_H
