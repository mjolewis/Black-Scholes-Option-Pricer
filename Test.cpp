/**********************************************************************************************************************
 * Black-Scholes Option Pricer
 *
 * Created by Michael Lewis on 7/27/20.
 *********************************************************************************************************************/

#include <iostream>

#include "Builder.hpp"
#include "EuropeanOption.hpp"
#include "Input.hpp"
#include "Pricer.hpp"
#include "RNG.hpp"

int main() {

    // Begin simulation
    std::cout << "\n--------------------------------------------------------------\n\n";
    std::cout << "\t\tBlack-Scholes Option Pricing Engine\n";
    std::cout << "\t\tAuthored By: Michael Lewis\n";
    std::cout << "\t\tStarting Pricing Engine\n";
    std::cout << "\n--------------------------------------------------------------" << std::endl;

    Builder<Input, RNG, Pricer> Builder;
    Builder.Build();

    std::cout << "\n--------------------------------------------------------------\n\n";
    std::cout << "\t\tSimulation complete";
    std::cout << "\n--------------------------------------------------------------" << std::endl;

    return 0;
}
