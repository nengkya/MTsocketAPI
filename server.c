/*
#define AF_INET 2; Internet Protocol (IP); Address Family InterNET
#define	SOL_SOCKET 0xffff; = 65535; options for socket level or SOcket Layer

int socket(int domain, int type, int protocol);
*/
#include <sys/socket.h>
#include <stdio.h>  /* perror(); */
#include <stdlib.h> /* EXIT_FAILURE */

int main(){

    int server_file_descriptor;
    
    /*
    1. Create socket

    Transmission Control Protocol (TCP) almost always uses SOCK_STREAM.
    User Datagram Protocol (UDP) uses SOCK_DGRAM.

    TCP (SOCK_STREAM) is a connection-based protocol.
    The connection is established and the two parties have a conversation
    until the connection is terminated by one of the parties or by a network error.

    UDP (SOCK_DGRAM) is a datagram-based protocol.
    You send one datagram and get one reply and then the connection terminates.

    If you send multiple packets, TCP promises to deliver them in order.
    UDP does not, so the receiver needs to check them, if the order matters.

    If a TCP packet is lost, the sender can tell. Not so for UDP.

    UDP datagrams are limited in size, from memory I think it is 512 bytes.
    TCP can send much bigger lumps than that.

    TCP is a bit more robust and makes more checks.
    UDP is a shade lighter weight (less computer and network stress).

    Bank use TCP.
    Online game use UDP.

    int socket(int domain, int type, int protocol);

    domain; Use AF_ LOCAL as defined in the POSIX standard for communication
    between processes on the same host.
    For communicating between processes on different hosts connected by IPV4, use AF_INET.

    int protocol; Specifies a particular protocol to be used with the socket.
    Specifying a protocol of 0 causes socket() to use an unspecified default protocol
    appropriate for the requested socket type.

    warning: suggest parentheses around assignment used as truth value [-Wparentheses]
    if (server_file_descriptor = socket(AF_INET, SOCK_STREAM, 0) < 0){
    */
    if ((server_file_descriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	/* print error */
	perror("socket failed.");
	/* The value of EXIT_FAILURE is defined in stdlib. h as 8; */
	exit(EXIT_FAILURE);
    }

    /*
    2. Set socket option

    This helps in manipulating options for the socket referred by the file descriptor sockfd.
    This is completely optional, but it helps in reuse of address and port.
    Prevents error such as: “address already in use”.

    int setsockopt(int sockfd, int level, int optname,  const void * option_value, socklen_t optlen);

    Forcefully attaching 1. Socket to the port 8000.
    */
    if (setsockopt(server_file_descriptor, SOL_SOCKET, )){


    }

}
