/*
 * BMI_record.cpp
 *
 *  Created on: Jan 14, 2022
 *      Author: basma
 */



#include "BMI_record.h"

std::vector< int > males ;
std::vector< int > females;
std::vector< int > males_bmis ;
std::vector< int > females_bmis;



/*
 * Function:  get_record
 * --------------------
 *  Description: gets singles's person record and store it in the supplied vectors
 *
 *  Parameters:
 *
 *		names    array of persons' full names
 *		heights  array of height in centimeters
 *		weights  array of weight in kilograms
 *		sexes    array of persons' sex: 'M' means male and 'F' means female
 *	Returns:
 *
 *		true to continue reading records or false to stop
 */

bool get_record (
		std::vector< std::string > &names,
		std::vector< int > &heights,
		std::vector< int > &weights,
		std::vector< char > &sexes)
{
	std::string name ;
	int height=0;
	int weight=0;
	char sex;
	char input;
	bool input_flag=false;


	std::cout << "enter new record ?"<<"'y'  or  'n':" ;
	std::cin >> input;

	if (input== 'y')
	{
		input_flag= true;
		std::cout <<"please enter your data "<<std::endl;

		std::cout << "Name:";
		std::cin >>name;
		names.push_back(name);

		std::cout << "Weight:";
		std::cin >>weight;
		weights.push_back(weight);

		std::cout << "Height:";
		std::cin >>height;
		heights.push_back(height);

		std::cout << "Sex:";
		std::cin >>sex;
		sexes.push_back(sex);


	}
	else if (input== 'n')
	{
		input_flag= false;

	}
	else
	{
		std::cout <<"wrong input,please try again"<<std::endl;
		input_flag=true;
	}
	return input_flag;
}


/*
 * Function:  print_table
 * --------------------
 *  Description: Print a table. Print a table of height, weight, sex, BMI, and name. Print only records for which sex
 *  			 matches sex. At the end of each table, print the mean and median BMI.
 *
 *  Parameters:
 *			sex the sex to match
 *			heights  the array of heights
 *			weights  the array of weights
 *			bmis     the array of BMIs
 *			sexes    the array of sexes
 *			names    the array of names
 *			threshold print only elements if it grater than or equal threshold
 *	Returns:
 *
 */
void print_table (
		char sex,
		std::vector< int > const &heights,
		std::vector< int > const &weights,
		std::vector< int > const &bmis,
		std::vector< char > const &sexes,
		std::vector< std::string > const &names,
		int threshold)
{

	for (int i=0;i<(sexes.size());i++)
	{

		if(sexes[i]=='m'|sexes[i]=='M')
		{
			males.push_back(i);
			males_bmis.push_back(bmis[i]);
		}
		else if(sexes[i]=='f'|sexes[i]=='F')
		{
			females.push_back(i);
			females_bmis.push_back(bmis[i]);
		}
	}


	if (sex=='m'|sex=='M')
	{
		std::cout<<std::endl<<"===================males Table=============================";
		for(int i=0;i<males.size();i++)
		{

			std::cout<<std::endl<<"name:"<<names[males[i]]<<"\tweight:"<<weights[males[i]]<<"\theight:"<<heights[males[i]]<<"\tsex:"<<sexes[males[i]];
			if(bmis[i]>threshold)
			{
				std::cout<<"\tBMI:"<<bmis[males[i]];
				std::cout<<"*";
			}
			else
			{
				// Do nnthing
			}
		}

		std::cout<<std::endl<<"===========================================================";

	}

	else if (sex=='f'|sex=='F')
	{
		std::cout<<std::endl<<"==================Females Table============================";


		for(int i=0;i<females.size();i++)
		{

			std::cout<<std::endl<<"name:"<<names[females[i]]<<"\tweight:"<<weights[females[i]]<<"\theight:"<<heights[females[i]]<<"\tsex:"<<sexes[females[i]];
			if(bmis[i]>threshold)
			{
				std::cout<<"\tBMI:"<<bmis[females[i]];
				std::cout<<"*";
			}
			else
			{
				// Do nnthing
			}

		}
		std::cout<<std::endl<<"===========================================================";

	}

}

