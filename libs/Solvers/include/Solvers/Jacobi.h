
#ifndef JACOBI_H
#define JACOBI_H

#include <iostream>
#include "Solvers/Solver.h"

class Jacobi : public Solver
{
public:
    Jacobi();
    ~Jacobi();
    void solve() override;
    void print() override;
};

#endif // JACOBI_H
