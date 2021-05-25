
#ifndef PLANNER_H
#define PLANNER_H

#define ROTATION_LIMIT_DEG 45

#include <vector>
#include "PathPlanning/Matrix.h"


class Planner
{
public:
    virtual std::vector<Matrix> get_path(const Matrix &start, const Matrix &goal);
private:
    virtual double cost();
};

#endif // PLANNER_H
