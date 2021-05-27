
#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <iostream>
#include "Solvers/Solver.h"

class GaussSeidel : public Solver
{
public:
    GaussSeidel();
    ~GaussSeidel();
    void solve() override;
    void print() override;
private:
    /* data */
};

#endif // GAUSSSEIDEL_H
