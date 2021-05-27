
#include "Solvers/SolverFactory.h"

Solver* SolverFactory::create(SOLVER &solver)
{
    switch (solver)
    {
        case LUDECOMP:
            return new LU();
            break;
        case JACOBI:
            return new Jacobi();
            break;
        case GAUSSSEIDEL:
            return new GaussSeidel();
            break;
        case SORELAX:
            return new SOR();
            break;
        
        default:
            return new Jacobi();
            break;
    }
}

Solver* SolverFactory::create() { return new Jacobi(); }
