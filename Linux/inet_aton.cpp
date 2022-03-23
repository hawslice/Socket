#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <arpa/inet.h>
using namespace std;

void error_handling(const string& message)
{
    cerr << message << endl;
    exit(-1);
}

int main(int argc, char *argv[])
{
    string addr_str = "127.232.124.79";
    const char *addr = addr_str.c_str();
    struct sockaddr_in addr_inet;

    if(!inet_aton(addr, &addr_inet.sin_addr))
        error_handling("Conversion error");
    else
        printf("Network ordered integer addr: %#x \n", addr_inet.sin_addr.s_addr);

    return 0;
}