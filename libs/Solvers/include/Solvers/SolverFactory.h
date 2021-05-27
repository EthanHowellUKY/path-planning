
#ifndef SOLVERFACTORY_H
#define SOLVERFACTORY_H

#include "Solvers/Solver.h"
#include "Solvers/LU.h"
#include "Solvers/Jacobi.h"
#include "Solvers/GaussSeidel.h"
#include "Solvers/SOR.h"

enum SOLVER {
    LUDECOMP=0,
    JACOBI,
    GAUSSSEIDEL,
    SORELAX
};

class SolverFactory
{
public:
    static Solver* create(SOLVER &solver);
    static Solver* create();
};

#endif // SOLVERFACTORY_H
