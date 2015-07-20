/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 15:39:30 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/20 22:07:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifdef WIN32

#include <winsock2.h>

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif

#define CRLF	 	"\r\n"
#define BUF_SIZE 	1024
#define MAX_CLIENTS 100
#define PORT		1234

typedef struct client{
	SOCKET	sock;
	char	name[BUF_SIZE];
}Client;

void init(void);
void end(void);
void end_connection(int sock);
int read_socket(SOCKET sock, char *buffer);
void write_socket(SOCKET sock, const char *buffer);

#endif /* guard */

