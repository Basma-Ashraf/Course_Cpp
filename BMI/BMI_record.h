/*
 * BMI_record.h
 *
 *  Created on: Jan 14, 2022
 *      Author: basma
 */

#ifndef BMI_RECORD_H_
#define BMI_RECORD_H_



#include <iostream>
#include <vector>
#include <string>
#include <cmath>


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


#endif /* BMI_RECORD_H_ */
