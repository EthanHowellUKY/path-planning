
#ifndef NODE_H
#define NODE_H

#include <math.h>
#include <vector>
#include "LinearAlgebra/Matrix.h"

class Node;

enum DIRECTION
{
    INCOMING = -1,
    BIDIRECTIONAL,
    OUTGOING
};

typedef struct {
    Node *dest;
    DIRECTION dir;
} Edge;

class Node
{
public:
    // -------------------------------- //
    //           CONSTRUCTORS           //
    // -------------------------------- //
    Node() {}
    Node(const int &id, const std::string &name, const std::vector<double> &origin);
    Node(const int &id, const std::string &name, const std::vector<double> &origin, const Matrix &orientation);
    Node(const int &id, const std::string &name, const Matrix &pose);

    // -------------------------------- //
    //            DESTRUCTOR            //
    // -------------------------------- //
    ~Node();

    // -------------------------------- //
    //            OPERATORS             //
    // -------------------------------- //
    bool                operator==(const Node &rhs) const;
    bool                operator!=(const Node &rhs) const;
    Matrix              operator*(const Node &rhs) const;
    Edge*               operator[](const int &idx);

    // -------------------------------- //
    //         PUBLIC FUNCTIONS         //
    // -------------------------------- //

    int connects_with(Node *node);
    void reset_cost();

    // ------------ GETTERS ----------- //
    Edge*               get_edge(const int &idx);
    Matrix              pose() const;
    Node*               parent();
    int                 num_edges() const;
    double              cost() const;
    std::string         name() const;
    int                 id() const;

    // ------------ SETTERS ----------- //
    void                reconfigure_edge(Edge *edge, const DIRECTION &dir, DIRECTION &out_dir);
    void                add_edge(Node *dest, const DIRECTION &dir);
    void                set_parent(Node *parent);
    void                set_cost(const double &cost);

    // -------------------------------- //
    //         PUBLIC VARIABLES         //
    // -------------------------------- //
    double f = __FLT_MAX__;
    double h = __FLT_MAX__;
    double g = __FLT_MAX__;
    bool has_parent;

private:
    // -------------------------------- //
    //        PRIVATE FUNCTIONS         //
    // -------------------------------- //
    Edge*               get_edge();

    // -------------------------------- //
    //        PRIVATE VARIABLES         //
    // -------------------------------- //
    Matrix              m_pose;
    Node                *m_parent;
    std::vector<Edge *> m_edges;
    const std::string   m_name;
    int                 m_id;
    double              m_cost = 0.0;
};

#endif // NODE_H
