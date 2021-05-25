
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
public:
    // -------------------------------- // 
	//           CONSTRUCTORS           //
	// -------------------------------- //
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<double> > &mat);
    Matrix(const char *filename);

    // COPY CONSTRUCTOR
    Matrix(const Matrix &);

    // -------------------------------- // 
	//            DESTRUCTOR            //
	// -------------------------------- //
    ~Matrix();

    // -------------------------------- // 
	//            OPERATORS             //
	// -------------------------------- //
    Matrix operator+(Matrix &rhs);
    Matrix operator-(Matrix &rhs);
    Matrix operator*(Matrix &rhs);
    Matrix operator=(const std::vector<std::vector<double> > &rhs);
    std::vector<double> operator*(std::vector<double> &rhs);
    double& operator()(const int &row, const int &col);
    double operator()(const int &row, const int &col) const;
    bool operator==(const Matrix &rhs) const;
    bool operator==(const std::vector<std::vector<double> > &rhs) const;

    // -------------------------------- // 
	//         PUBLIC FUNCTIONS         //
	// -------------------------------- //
    Matrix transpose();
    static std::vector<double> solve(const Matrix &A, const std::vector<double> b);

    // ------------ GETTERS ----------- //
    int rows() const;
    int cols() const;

    // ------------ SETTERS ----------- //

private:
    // -------------------------------- // 
	//        PRIVATE FUNCTIONS         //
	// -------------------------------- //
    bool is_valid();
    void add_sub(Matrix &mat, Matrix &lhs, Matrix &rhs, const int &op);

    // -------------------------------- // 
	//        PRIVATE VARIABLES         //
	// -------------------------------- //
    int m_rows;
    int m_cols;
    std::vector<std::vector<double> > m_matrix;
};

#endif // MATRIX_H
