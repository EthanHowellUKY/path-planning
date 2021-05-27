
#ifndef SOR_H
#define SOR_H

#include <iostream>
#include "Solvers/Solver.h"

class SOR : public Solver
{
public:
    SOR();
    ~SOR();
    void solve() override;
    void print() override;
private:
    
};

#endif // SOR_H
