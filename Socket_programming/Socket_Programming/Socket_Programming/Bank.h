//
//  Bank.h
//  Socket_Programming
//
//  Created by Basma on 26/01/2022.
//

#ifndef Bank_h
#define Bank_h
#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>
#include <sstream>

#include <iostream>
#define PORTA 8000


class Bank_Accounts{
    private:
    
std::string name;
int Balance;
    
public:
    
void display()
    {
    std::cout<<name<<"\tBal : "<<Balance<<std::endl;
}
void Set_Amount(int money){
    Balance=money;
}
    
    
void Set_Name(char* Client_name)
    {
        for(int i=0;Client_name[i]!='\0';i++)
        {
            name.insert(i,1,Client_name[i]) ;
        }
    }
};


#endif /* Bank_h */
