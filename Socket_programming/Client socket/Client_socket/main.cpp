//
//  main.cpp
//  Client socket
//
//  Created by Basma on 26/01/2022.
//

#include <iostream>

#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <sstream>
#include <iostream>
#define PORTA 8000

int main(int argc, const char * argv[])
{
    //============create server socket==========================
    struct sockaddr_in Server_addr =
    {
        //IPv4
        .sin_family=AF_INET,
        .sin_addr.s_addr=INADDR_ANY,
        .sin_port=htons(PORTA)
    };
    std::string IPaddr = "127.0.0.1";
    
    /* Convert IPv4 and IPv6 addresses from text to binary form*/
    inet_pton(AF_INET,IPaddr.c_str(), &Server_addr.sin_addr);
    
    int ServerAddrSize=sizeof(Server_addr);
    
        
    /*======cheching for socket creation validity==============*/
    int SOCKET= socket(AF_INET,SOCK_STREAM,0);
    
    if(SOCKET==-1)
    {
        std::cerr<<"not able to create our socket !" <<std::endl;
        return -1;
    }
    
    /*==========establish connection with server==========*/
    
    int check_connection = connect(SOCKET,(sockaddr *)&Server_addr,ServerAddrSize);
    
        if(check_connection<0)
        {
            std::cerr<<"Connection failed"<<std::endl;
            return 0;
        }
    
    
    std::string  input;
    char buff[4096];
   long  sizeinBytesOfRecievedData=recv(SOCKET,buff,sizeof(buff),0);

        do
        {
            //recieve requests
            memset(buff,0,sizeof(buff));
            
            if (sizeinBytesOfRecievedData>0)
                {
                    std::cout<<std::string(buff,0,sizeinBytesOfRecievedData);
                }
                else if (sizeinBytesOfRecievedData==-1)
                {
                    std::cerr<<"error recieving message"<<std::endl;
                    return 0;
                }
            getline(std::cin,input);
           if(input.size()>0)
            {
                //send data
               long SendResult= send(SOCKET, input.c_str(),sizeof(input)+1,0);//+1 for null char
                if(SendResult==0)
                {
                    std::cerr<<"unable to send "<<std::endl;
                    return 0;
                }
                //recieve echo
                memset(buff,0,sizeof(buff));//clear the buffer
                sizeinBytesOfRecievedData=recv(SOCKET,buff,sizeof(buff),0);
                if (sizeinBytesOfRecievedData>0)
                {
                    //string(string that will be shown ,starting from index i,number of characters shown)
                    std::cout<<"Echo:"<<std::string(buff,0,sizeinBytesOfRecievedData)<<std::endl;
                }
                else if (sizeinBytesOfRecievedData==-1)
                {
                    std::cerr<<"error recieving message"<<std::endl;
                    return 0;
                }
            }
        } while (input.size()>0);
    close(SOCKET);
    
    
}
