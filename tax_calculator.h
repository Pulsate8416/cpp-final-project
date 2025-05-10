#pragma once
#include <string>

double calculateTax(double propertyValue);
double calculateTax(double propertyValue, double exemption); // Overloaded
bool isValidPropertyValue(const std::string& input);