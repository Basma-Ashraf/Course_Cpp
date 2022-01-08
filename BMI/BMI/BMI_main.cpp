#include "BMI_BSW.h"

std::vector< int > heights;
std::vector< int > weights;
std::vector< int > bmis;
std::vector< char > sexes;
std::vector< std::string > names;
std::vector< char > males ;
std::vector< char > females;
std::vector< char > males_bmis ;
std::vector< char > females_bmis;
bool result{false};
int thrshold{0};
int Index{0};

int main ()

{
    std::cout << "enter BMI threshold:";
    std::cin >> thrshold;


    do
    {
    result = get_record(names,heights,weights,sexes);
    }
    while (result==true);

    print_table('m',heights,weights,bmis,sexes,names,thrshold);
    print_table('f',heights,weights,bmis,sexes,names,thrshold);

    return 0 ;
}

bool get_record (
    std::vector< std::string > &names,
    std::vector< int > &heights,
    std::vector< int > &weights,
    std::vector< char > &sexes)
    {
         std::string name ;
         int height{0};
         int weight{0};
         char sex{};
         char input{};
         bool input_flag{false};
         

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

                bmis.push_back( compute_bmi (heights[Index],weights[Index]));
                std::cout <<"BMI:"<<bmis[Index]<<std::endl;
                Index++;

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



void print_table (
    char sex,
    std::vector< int > const &heights,
    std::vector< int > const &weights,
    std::vector< int > &bmis,
    std::vector< char > const &sexes,
    std::vector< std::string > const &names,
    int threshold)
    {
        float median{0.0};
        float mean{0.0};
        int bmi_sum{0};

       if (sex=='m'|sex=='M')
        {
             for (int i=0;i<(sexes.size());i++)
             {
                 if(sexes[i]=='m'|sexes[i]=='M')
                 {
                     males.push_back(i);
                     males_bmis.push_back(bmis[i]);
                 }
             }
                 std::cout<<std::endl<<"Males Table";
            for(int i=0;i<males.size();i++)
            {
                if(threshold<bmis[i])
                {
                std::cout<<std::endl<<"name:"<<names[males[i]]
                <<"\tweight:"<<weights[males[i]]
                <<"\theight:"<<heights[males[i]]
                <<"\tsex:"<<sexes[males[i]]
                <<"\tBMI:"<<bmis[males[i]];

                
                    std::cout<<"*";
                }
                else
                {
                    // Do nnthing
                }

                std::cout<<std::endl;
                 bmi_sum+=bmis[males[i]];
                 mean=(bmi_sum/males.size());
            }
         for(int i=0;i<males_bmis.size();i++)
         {
             for(int j=1;j<(males_bmis.size()-1);j++)
            {
                if (males_bmis[i]>males_bmis[j])
                {
                    int temp=males_bmis[i];
                    males_bmis[i]=males_bmis[j];
                    males_bmis[j]=temp;
                }
               // bmi_sum+=bmis[i];
            }
         }


             
                if((males_bmis.size()%2)==0)
                {
                   median=(males_bmis[males_bmis.size()/2]+males_bmis[(males_bmis.size()+1/2)])/2;
                }
                else
                {
                    median=males_bmis[males_bmis.size()/2];
                }

        }   
            
        else if (sex=='f'|sex=='F')
        {
             for (int i=0;i<sexes.size();i++)
             {
                 if(sexes[i]=='f'|sexes[i]=='F')
                 {  
                    females.push_back(i);
                 }
             }
            std::cout<<std::endl<<"Females Table";
            for(int i=0;i<females.size();i++)
            {
                if(threshold<bmis[i])
                {
                 std::cout<<std::endl<<"name:"<<names[females[i]]
                 <<"\tweight:"<<weights[females[i]]
                 <<"\theight:"<<heights[females[i]]
                 <<"\tsex:"<<sexes[females[i]]
                 <<"\tBMI:"<<bmis[females[i]];

                 
                    std::cout<<"*";
                }
                else
                {
                    
                }
                std::cout<<std::endl;
                bmi_sum+=bmis[females[i]];
                mean=(bmi_sum/females.size());

            }
            for(int i=0;i<females_bmis.size();i++)
         {
             for(int j=1;j<(females_bmis.size()-1);j++)
            {
                if (females_bmis[i]>females_bmis[j])
                {
                    int temp=females_bmis[i];
                    females_bmis[i]=females_bmis[j];
                    females_bmis[j]=temp;
                }
               // bmi_sum+=bmis[i];
            }
         }


             
                if((females_bmis.size()%2)==0)
                {
                   median=(females_bmis[females_bmis.size()/2]+females_bmis[(females_bmis.size()+1/2)])/2;
                }
                else
                {
                    median=females_bmis[females_bmis.size()/2];
                }
        } 
                


               
               std::cout<<std::endl<<"mean:"<<mean<<"\tmedian:"<<median;
    }
    

int compute_bmi (int height, int weight)
{
    float height_total=((height * height)/10000.0);
    float bmi = (weight/height_total);
    return ((int) (bmi+0.5));
}