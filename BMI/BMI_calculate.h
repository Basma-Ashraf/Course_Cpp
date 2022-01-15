/*
 * BMI_calculate.h
 *
 *  Created on: Jan 14, 2022
 *      Author: basma
 */

#ifndef BMI_CALCULATE_H_
#define BMI_CALCULATE_H_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

int compute_bmi (int height, int weight);

void compute_median_BMI(std::vector <int> BMI_list);

void compute_mean_BMI(std::vector <int> BMI_list);

//void sort(std::vector <int> BMI_list);


#endif /* BMI_CALCULATE_H_ */
