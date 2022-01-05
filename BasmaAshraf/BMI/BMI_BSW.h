#ifndef BMI_BSW_H
#define BMI_BSW_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

void skip_line ();

int compute_bmi (int height, int weight);


bool get_record (
    std::vector< std::string > &names,
    std::vector< int > &heights,
    std::vector< int > &weights,
    std::vector< char > &sexes);

void print_table (
    char sex,
    std::vector< int > const &heights, std::vector< int > const &weights, std::vector< int > const &bmis,
    std::vector< char > const &sexes, std::vector< std::string > const &names,
    int threshold);


#endif