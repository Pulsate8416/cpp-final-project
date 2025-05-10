#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "tax_calculator.h"
#include "file_utils.h"

int main() {
    std::string name, propertyInput;
    double propertyValue = 0.0, exemption = 0.0;
    char useExemption;
    std::vector<std::string> results;

    std::cout << "Enter your name (LAST FIRST): ";
    std::getline(std::cin, name);

    // Input validation for property value
    while (true) {
        std::cout << "Enter your property value (USD): ";
        std::getline(std::cin, propertyInput);
        if (isValidPropertyValue(propertyInput)) {
            propertyValue = std::stod(propertyInput);
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }

    // Optional: Homestead exemption
    std::cout << "Do you have a homestead exemption? (y/n): ";
    std::cin >> useExemption;
    if (useExemption == 'y' || useExemption == 'Y') {
        std::cout << "Enter exemption amount (USD): ";
        std::cin >> exemption;
    }

    double taxOwed = (exemption > 0) ? calculateTax(propertyValue, exemption) : calculateTax(propertyValue);

    std::ostringstream oss;
    oss << "Name: " << name << "\nProperty Value: $" << propertyValue
        << "\nTax Owed: $" << std::fixed << std::setprecision(2) << taxOwed << "\n";
    std::cout << oss.str();

    saveResultToFile("tax_results.txt", oss.str());

    return 0;
}