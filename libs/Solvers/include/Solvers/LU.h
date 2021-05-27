
#ifndef LU_H
#define LU_H

#include <iostream>
#include "Solvers/Solver.h"

class LU : public Solver
{
public:
    LU();
    ~LU();
    void solve() override;
    void print() override;
private:
    
};

#endif // LU_H
