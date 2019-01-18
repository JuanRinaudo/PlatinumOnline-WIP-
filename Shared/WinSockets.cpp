#include <WS2tcpip.h>
#include <stdlib.h>


#include "Sockets.h"

/*
SOCKET create_udp (SockAddr address) {

    

    SOCKET udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
    return udpSocket;
}
*/

sockaddr_in create_socket_address (int ipv4_address, int port) {

    sockaddr_in address;
    memset(address.sin_zero, 0, sizeof(address.sin_zero));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.S_un.S_addr = htonl(ipv4_address);
    return address;
}

sockaddr_in create_socket_address (char* source, int port)
{
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	int error = inet_pton(address.sin_family, source, &address.sin_addr);
	//TODO handle error
	return address;

}

int bind_udp_socket (SOCKET socket, const sockaddr * to_address) {

	int error = bind (socket, to_address, sizeof(to_address));
	return error;
}

int send_to (const void* data, int length, const sockaddr* to_address) {

}

int receive_from (void* buffer, int length, sockaddr* from)
{

}


int inet_pton(int af, const char *src, void *dst)
{
    struct sockaddr_storage ss;
    int size = sizeof(ss);
    char src_copy[INET6_ADDRSTRLEN+1];

    ZeroMemory(&ss, sizeof(ss));
    /* stupid non-const API */
    strncpy (src_copy, src, INET6_ADDRSTRLEN+1);
    src_copy[INET6_ADDRSTRLEN] = 0;

    if (WSAStringToAddress(src_copy, af, NULL, (struct sockaddr *)&ss, &size) == 0) {
        switch(af) {
            case AF_INET:
                *(struct in_addr *)dst = ((struct sockaddr_in *)&ss)->sin_addr;
                return 1;
            case AF_INET6:
                *(struct in6_addr *)dst = ((struct sockaddr_in6 *)&ss)->sin6_addr;
            return 1;
        }
    }
  return 0;
}

const char *inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
    struct sockaddr_storage ss;
    unsigned long s = size;

    ZeroMemory(&ss, sizeof(ss));
    ss.ss_family = af;

    switch(af) {
        case AF_INET:
        ((struct sockaddr_in *)&ss)->sin_addr = *(struct in_addr *)src;
        break;
    case AF_INET6:
        ((struct sockaddr_in6 *)&ss)->sin6_addr = *(struct in6_addr *)src;
        break;
    default:
      return NULL;
    }
    /* cannot direclty use &size because of strict aliasing rules */
    return (WSAAddressToString((struct sockaddr *)&ss, sizeof(ss), NULL, dst, &s) == 0)? dst : NULL;
}