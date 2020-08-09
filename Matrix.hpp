/**********************************************************************************************************************
 * Utility class to generate matrices
 *
 * Created by Michael Lewis on 8/9/20.
 *********************************************************************************************************************/

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

#include "Option.hpp"

class Matrix {
private:
public:
    Matrix();
    Matrix(const Matrix& source);
    virtual ~Matrix();

    // Operator overloading
    Matrix& operator=(const Matrix& source);

    // Generate matrices
    std::vector<std::vector<double>> getMatrix(const std::vector<double>& mesh, const Option& option, const std::string& property);

};


#endif // MATRIX_HPP