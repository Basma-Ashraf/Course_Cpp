/*
 * BMI_main.cpp
 *
 *  Created on: Jan 14, 2022
 *      Author: basma
 */

#include "BMI_calculate.h"
#include "BMI_record.h"


std::vector< int > heights;
std::vector< int > weights;
std::vector< int > bmis;
std::vector< char > sexes;
std::vector< std::string > names;
extern std::vector< int > males_bmis ;
extern std::vector< int > females_bmis;
bool result=false;
int threshold=0;



int main ()

{
	// get BMI threshold from user
   std::cout << "enter BMI threshold:";
    std::cin >> threshold;


    //
    do
    {
    	//passes the entered values to the vectors and return the flag in result
    	result = get_record(names,heights,weights,sexes);
    	//put the calculated BMI results in bmis (vector)
    	bmis.push_back(compute_bmi (heights.back(),weights.back()));
    	//print the calculated BMI for each record
    	std::cout <<"BMI:"<<bmis.back()<<std::endl;

    }//continue reading as long as the flag is true
    while (result==true);

    // printing males table
    print_table('m',heights,weights,bmis,sexes,names,threshold);
    //printing mean of males BMIs
    compute_mean_BMI(males_bmis);
    //printing median of males BMIs
    compute_median_BMI(males_bmis);



    // printing females table
    print_table('f',heights,weights,bmis,sexes,names,threshold);
    //printing mean of females BMIs
    compute_mean_BMI(females_bmis);
    //printing median of females BMIs
    compute_median_BMI(females_bmis);



    return 0 ;
}

