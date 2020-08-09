/**********************************************************************************************************************
 * Utility class to generate matrices
 *
 * Created by Michael Lewis on 8/9/20.
 *********************************************************************************************************************/

#include "Matrix.hpp"

// Initialize a new matrix
Matrix::Matrix() {}

// Create a deep copy of the source
Matrix::Matrix(const Matrix &source) {}

// Destroy this matrix
Matrix::~Matrix() {}

Matrix & Matrix::operator=(const Matrix &source) {
    // Avoid self assign
    if (this == &source) {return *this;}

    return *this;
}

/**
 * Create a matrix of option parameters. Each row will variate one parameter by a monotonically increasing amount
 * @param mesh A mesh array
 * @param option The initial option parameters
 * @param property The variate parameter, which should be represented by the variate symbol (e.g. T, sig, r, S, K, b)
 * @return A {@link std::vector<std::vector<double> > of option parameters
 */
std::vector<std::vector<double>>
Matrix::getMatrix(const std::vector<double>& mesh, const Option &option, const std::string &property) {

    // Create a new output container for each new matrix
    std::vector<std::vector<double>> matrix;

    // Use the mesh points to modify property by a monotonically increasing amount
    if (property == "T" || property == "t" || property == "Expiry" || property == "expiry") {

        // Monotonically increase expiry and add the new option to a new row in the matrix
        for (double T : mesh) {
            matrix.push_back({T, option.vol(), option.riskFree(), option.spot(), option.strike(), option.carry()});
        }
    } else if (property == "Sig" || property == "sig" || property == "Volatility" || property == "volatility" ) {

        // Monotonically increase vol and add the new option to a new row in the matrix
        for (double sig : mesh) {
            matrix.push_back({option.expiry(), sig, option.riskFree(), option.spot(), option.strike(), option.carry()});
        }
    } else if (property == "R" || property == "r" || property == "Risk-free" || property == "risk-free" ) {

        // Monotonically increase risk free rate and add the new option to a new row in the matrix
        for (double r : mesh) {
            matrix.push_back({option.expiry(), option.vol(), r, option.spot(), option.strike(), option.carry()});
        }
    } else if (property == "S" || property == "s" || property == "Spot" || property == "spot" ) {

        // Monotonically increase spot price and add the new option to a new row in the matrix
        for (double S : mesh) {
            matrix.push_back({option.expiry(), option.vol(), option.riskFree(), S, option.strike(), option.carry()});
        }
    } else if (property == "K" || property == "k" || property == "Strike" || property == "strike" ) {

        // Monotonically increase strike price and add the new option to a new row in the matrix
        for (double K : mesh) {
            matrix.push_back({option.expiry(), option.vol(), option.riskFree(), option.spot(), K, option.carry()});
        }
    } else if (property == "B" || property == "b" || property == "Beta" || property == "beta" ) {

        // Monotonically increase beta and add the new option to a new row in the matrix
        for (double b : mesh) {
            matrix.push_back({option.expiry(), option.vol(), option.riskFree(), option.spot(), option.strike(), b});
        }
    }

    return matrix;
}