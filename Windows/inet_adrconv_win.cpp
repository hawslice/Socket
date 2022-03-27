#include <cstdio>
#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

void error_handling(const string& message)
{
    cerr << message << endl;
    exit(-1);
}

int main()
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        error_handling("WSAStartup() error!");

    // inet_addr函数调用示例
    {
        const char *addr = "127.212.124.78";
        unsigned long conv_addr = inet_addr(addr);
        if (conv_addr == INADDR_NONE)
            cerr << "Error occured!" << endl;
        else
            printf("Network ordered address: %#lx \n", conv_addr);
    }

    // inet_ntoa函数调用示例
    {
        struct sockaddr_in addr;
        char *strPtr;
        char strArr[20];

        addr.sin_addr.s_addr = htonl(0x1020304);
        strPtr = inet_ntoa(addr.sin_addr);
        strcpy(strArr, strPtr);
        printf("Dotted-Decimal notation3 %s \n", strArr);
    }


    WSACleanup();

    return 0;
}