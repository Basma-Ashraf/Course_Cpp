/*
 * BMI_calculate.cpp
 *
 *  Created on: Jan 14, 2022
 *      Author: basma
 */


#include "BMI_calculate.h"

float median=0.0;
float mean=0.0;
float BMI_sum=0;




/*
 * Function:  compute_bmi
 * --------------------
 *  Description: calculate the body mass index of a person's record based on function BMI=weight/height^2
 *
 *  Parameters:
 *  	height The person's height in centimeters
 *  	weight The person's weight in kilograms.
 *
 *  Returns:
 *  	the person's BMI, rounded to an integer
 *
 */

int compute_bmi (int height, int weight)
{
    float height_total=((height * height)/10000.0);
    float bmi = (weight/height_total);
    return ((int) (bmi+0.5));
}



/*
 * Function:  compute_bmi
 * --------------------
 *  Description: calculate the median of BMI list
 *
 *  Parameters:
 *  	BMI_list the list to be calculated
 *
 *  Returns:
 *
 *
 */
void compute_median_BMI(std::vector <int> BMI_list)
{

	std::sort(BMI_list.begin(),BMI_list.end());
	int loc=0;
    if((BMI_list.size()%2)==0)
    {
       loc=BMI_list.size()/2;
       int sum=BMI_list[3]+BMI_list[2];
       median=(float)sum/2;

    }
    else
    {
    	loc=(BMI_list.size()/2);
    	median=(float)BMI_list[loc];
    }
    std::cout<<std::endl<<"median:"<<median;


}


/*
 * Function:  compute_bmi
 * --------------------
 *  Description: calculate the mean of BMI list
 *
 *  Parameters:
 *  	BMI_list the list to be calculated
 *
 *  Returns:
 *
 *
 */
void compute_mean_BMI(std::vector <int> BMI_list)
{
	for(const auto & BMI:BMI_list)
	{
		BMI_sum+=BMI;
	}
		mean=(BMI_sum/BMI_list.size());

		std::cout << std::setprecision(3);
		std::cout<<std::endl<<"mean:"<<mean;
}



