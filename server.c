/*
#define AF_INET 2; Internet IP Protocol; Address Family InterNET
*/
#include <sys/socket.h> /* socket(); */
#include <stdio.h>	/* perror(); */
#include <stdlib.h>	/* EXIT_FAILURE */

int main(){

    int server_file_descriptor;
    
    /*
    User Datagram Protocol, or UDP

    Transmission Control Protocol (TCP) almost always uses SOCK_STREAM and UDP uses SOCK_DGRAM.

TCP (SOCK_STREAM) is a connection-based protocol. The connection is established and the two parties have a conversation until the connection is terminated by one of the parties or by a network error.

UDP (SOCK_DGRAM) is a datagram-based protocol. You send one datagram and get one reply and then the connection terminates.

    If you send multiple packets, TCP promises to deliver them in order. UDP does not, so the receiver needs to check them, if the order matters.

    If a TCP packet is lost, the sender can tell. Not so for UDP.

    UDP datagrams are limited in size, from memory I think it is 512 bytes. TCP can send much bigger lumps than that.

    TCP is a bit more robust and makes more checks. UDP is a shade lighter weight (less computer and network stress).

    Bank use TCP.
    Online game use UDP.
*/
    if (server_file_descriptor = socket(AF_INET, SOCK_STREAM, ) < 0){
	/* print error */
	perror("socket failed.");
	/* The value of EXIT_FAILURE is defined in stdlib. h as 8; */
	exit(EXIT_FAILURE);
    }

}
