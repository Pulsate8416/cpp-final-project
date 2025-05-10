//
// Created by u on 5/7/25.
//

#include "tax_calculator.h"
#include <sstream>
#include <iomanip>

double calculateTax(double propertyValue) {
    // Example: 2.5% property tax rate
    return propertyValue * 0.025;
}

double calculateTax(double propertyValue, double exemption) {
    double taxable = propertyValue - exemption;
    if (taxable < 0) taxable = 0;
    return taxable * 0.025;
}

bool isValidPropertyValue(const std::string& input) {
    std::istringstream iss(input);
    double val;
    iss >> std::noskipws >> val;
    return iss.eof() && !iss.fail() && val >= 0;
}