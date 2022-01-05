#include "BMI_BSW.h"

std::vector< int > heights;
std::vector< int > weights;
std::vector< int > bmis;
std::vector< char > sexes;
std::vector< std::string > names;
std::vector< char > males ;
std::vector< char > females;

bool result=false;
int thrshold=0;
int Index = 0;
int main ()
{
    std::cout << "enter BMI threshold:";
    std::cin >> thrshold;


 do
{
    result = get_record(names,heights,weights,sexes);
    
    

}   while (result==true);
print_table('m',heights,weights,bmis,sexes,names,thrshold);

    return 0 ;
}

bool get_record (
    std::vector< std::string > &names,
    std::vector< int > &heights,
    std::vector< int > &weights,
    std::vector< char > &sexes)
    {
         std::string name ;
         int height;
         int weight;
         char sex;
         char input;
         bool input_flag=false;

        std::cout << "enter new record ?"<<"'y'or'n':" ;
        std::cin >> input;

            if (input== 'y')
            {
                input_flag= true;
                std::cout <<"please enter your data :"<<std::endl;
                
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
           


            bmis.push_back( compute_bmi (heights[Index],weights[Index]));
            std::cout <<"BMI:"<<bmis[Index]<<std::endl;
            Index++;
             return input_flag;
    }



void print_table (
    char sex,
    std::vector< int > const &heights,
    std::vector< int > const &weights,
    std::vector< int > const &bmis,
    std::vector< char > const &sexes,
    std::vector< std::string > const &names,
    int threshold)
    {
        float median=0;
        float mean=0;
       if (sex=='m'|sex=='M')
        {
             for (int i=0;i<(sexes.size());i++)
             {
                 if(sexes[i]==sex)
                 {
                     males.push_back(i);
                 }
             }
                 std::cout<<"Males Table"<<std::endl;
            for(int i=0;i<males.size();i++)
             {
                std::cout<<std::endl<<"name:"<<names[males[i]]<<"\tweight:"<<weights[males[i]]
                <<"\theight:"<<heights[males[i]]
                <<"\tsex:"<<sexes[males[i]]
                <<"\tBMI:"<<bmis[males[i]];

            if(threshold<bmis[i])
            {
                std::cout<<"*";
            }
            else
            {
                continue;
            }

                std::cout<<std::endl;
             }
        }    9+-
            
        else if (sex=='f'|sex=='F')
        {
             for (int i=0;i<sexes.size();i++)
             {
                 if(sexes[i]==sex)
                 {  
                    females.push_back(i);
                 }
             }
            std::cout<<"Females Table"<<std::endl;
            for(int i=0;i<females.size();i++)
             {
                 std::cout<<std::endl<<"name:"<<names[females[i]]<<"\tweight:"<<weights[females[i]]
                 <<"\theight:"<<heights[females[i]]
                 <<"\tsex:"<<sexes[females[i]]
                 <<"\tBMI:"<<bmis[females[i]];
            }
        } 
         for(int i=0;i<bmi.size();i++)
         {
             for(int j=1;j<(bmi.size()-1);j++)
            {
                if (bmis[i]>bmis[j])
                {
                    int temp=bmis[i];
                    bmis[i]=bmis[j];
                    bmis[j]=temp;
                }
            }
         }

         for(int i=0;i<bmi.size();i++)
         {
             mean=
         }


    }

    int compute_bmi (int height, int weight)
{
    float height_total=((height * height)/10000.0);
    float bmi = (weight/height_total);
    return ((int) (bmi+0.5));
}