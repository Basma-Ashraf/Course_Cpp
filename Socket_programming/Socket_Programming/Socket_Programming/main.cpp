//
//  main.cpp
//  Socket_Programming
//
//  Created by Basma on 25/01/2022.
//

#include "Bank.h"

int main(int argc, const char * argv[])

{
    //============create server socket==========================
    struct sockaddr_in Server_addr=
    {
        //IPv4
        .sin_family=AF_INET,
        .sin_addr.s_addr=INADDR_ANY,
        .sin_port=htons(PORTA)
    };
    
    int option =1;
    int Server_addrSize=sizeof(Server_addr);
    int socketServer= socket(AF_INET,SOCK_STREAM,0);
    setsockopt(socketServer, SOL_SOCKET,(SO_REUSEADDR|SO_REUSEPORT), &option, sizeof(option));
    
    if(socketServer==-1)
    {
        std::cerr<<"not able to create our socket !" <<std::endl;
        return -1;
    }
    /*==========================================================*/
    
    
    //============create client socket==========================
    struct sockaddr_in Client_addr;
    socklen_t caddrSize=sizeof(Client_addr);
    
    //int Client_socket=socket(AF_INET,SOCK_STREAM,0);
    /*=======================================*/
    
    /*======binding our socket to port +ip===============*/
    bind(socketServer,(struct sockaddr*)&Server_addr, Server_addrSize);
    /*====================================================*/
    
    /*==========listening================================*/
    listen(socketServer, SOMAXCONN);
    //max number of clients can connect to the server
    /*===================================================*/
    
    //print
    std::stringstream ss;
    ss<< PORTA;
    std::cout <<"[Server] Listining on port "<<ss.str()<<std::endl;
    ///
    //
    
    char buff[4096];
    long sizeinBytesOfRecievedData;
    
    int Client_socket =accept(socketServer, (struct sockaddr*)&Client_addr, (socklen_t*)&caddrSize);
    
    //waiting for client
    while(true)
    {
        //accept connection from clients
       
        std::cout<<"[Server] Client connected successfully."<<std::endl;
        
        
        //try to find out who is the client
        char hostClient[NI_MAXHOST];
        char portClient[NI_MAXSERV];
        memset(hostClient,0,NI_MAXHOST);
        memset(portClient,0,NI_MAXSERV);
        
        if (getnameinfo((sockaddr*)&Client_addr, sizeof(Client_addr), hostClient, NI_MAXHOST, portClient, NI_MAXSERV, 0)==0)
        {
            std::cout<<"-->"<<hostClient<<"connected to the port"<<portClient<<std::endl;
        }
        
        else
        {
            inet_ntop(AF_INET, &Client_addr.sin_addr, hostClient, NI_MAXHOST);
        
        std::cout<<"-->"<<hostClient <<" Connected to Port"<<ntohs((Client_addr.sin_port))<<std::endl;
        }
        
        
        
        //Recieve out data
        
        sizeinBytesOfRecievedData=recv(Client_socket, buff, 4096, 0);
        if (sizeinBytesOfRecievedData==-1) {
            std::cerr<<"error recieving message.";
            break;
        } else if (sizeinBytesOfRecievedData==0)
        {
            std::cout <<"client disconnected"<<std::endl;
            break;
        }
        
        
        
        send(Client_socket, buff, sizeinBytesOfRecievedData+1, 0);
        
        
        std::cout<<std::string(buff,0,sizeinBytesOfRecievedData)<<std::endl;
        
        //close(Client_socket);
        
    }
   
       std::string Name_str="Name";
       std::string Balance_str="Balance";
       std::vector<Bank_Accounts> Bank;
       Bank_Accounts temp;
       int Input_Specifier=0;
       int counter =0;
    
       while(1)
       {
           //send name request
           if(Input_Specifier==0)
           {
               send(Client_socket,Name_str.c_str(),sizeof(Name_str)+1,0);
              
           }
           //send amount request
           else if(Input_Specifier==1)
           {
               send(Client_socket,Balance_str.c_str(),sizeof(Balance_str)+1,0);
               
           }
           //recieve data
           memset(buff,0,4096);
           long BytesRecieved=recv(Client_socket,buff,4096,0);

           if (BytesRecieved==-1)
           {
               std::cerr<<"Recieving failed "<<std::endl;
               break;
           }
           else if(BytesRecieved==0)
           {
               std::cout<<"Client disconnected"<<std::endl;
               break;
           }
           
           if(Input_Specifier==0)//saving name
           {
               temp.Set_Name(buff);
            //   std::cout<<"NAME: "<<std::string(buffer,0,BytesRecieved)<<std::endl;
               Input_Specifier=1;
           }
           else if(Input_Specifier==1)//saving amount
           {
               counter++;
               temp.Set_Amount(atoi(buff));
              // std::cout<<"Amount: "<<std::string(buffer,0,BytesRecieved)<<std::endl;
               Bank.push_back(temp);
               Input_Specifier=0;
                   std::cout<<counter<<")";
                   Bank.back().display();

           }
           //echo back
           send(Client_socket,buff,BytesRecieved+1,0);

       }
       close(Client_socket);
    return 0;
}
