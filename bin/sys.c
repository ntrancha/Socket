/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 21:15:25 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/20 23:35:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/includes/libft.h"

void init(void)
{
#ifdef WIN32
		WSADATA wsa;
		int err = WSAStartup(MAKEWORD(2, 2), &wsa);
		if(err < 0)
		{
				puts("WSAStartup failed !");
				exit(EXIT_FAILURE);
		}
#endif
}

void end(void)
{
#ifdef WIN32
		WSACleanup();
#endif
}

void end_connection(int sock)
{
		closesocket(sock);
}

int read_socket(SOCKET sock, char *buffer)
{
		int n = 0;

		if((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
		{
				perror("recv()");
				exit(errno);
		}
		buffer[n] = 0;
		return n;
}

void write_socket(SOCKET sock, const char *buffer)
{
		if(send(sock, buffer, strlen(buffer), 0) < 0)
		{
				perror("send()");
				exit(errno);
		}
}
