/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 15:39:52 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/20 23:35:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "client.h"
#include "libft/includes/libft.h"

static void app(const char *address, const char *port, const char *name)
{
		SOCKET sock = init_connection(address, port);
		char buffer[BUF_SIZE];

		fd_set rdfs;

		/* send our name */
		write_socket(sock, name);

		while(1)
		{
				FD_ZERO(&rdfs);

				/* add STDIN_FILENO */
				FD_SET(STDIN_FILENO, &rdfs);

				/* add the socket */
				FD_SET(sock, &rdfs);

				if(select(sock + 1, &rdfs, NULL, NULL, NULL) == -1)
				{
						perror("select()");
						exit(errno);
				}

				/* something from standard input : i.e keyboard */
				if(FD_ISSET(STDIN_FILENO, &rdfs))
				{
						fgets(buffer, BUF_SIZE - 1, stdin);
						{
								char *p = NULL;
								p = strstr(buffer, "\n");
								if(p != NULL)
								{
										*p = 0;
								}
								else
								{
										/* fclean */
										buffer[BUF_SIZE - 1] = 0;
								}
						}
						write_socket(sock, buffer);
				}
				else if(FD_ISSET(sock, &rdfs))
				{
						int n = read_socket(sock, buffer);
						/* server down */
						if(n == 0)
						{
								printf("Server disconnected !\n");
								break;
						}
						puts(buffer);
				}
		}

		end_connection(sock);
}

static int init_connection(const char *address, const char *port)
{
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		SOCKADDR_IN sin = { 0 };
		struct hostent *hostinfo;

		if(sock == INVALID_SOCKET)
		{
				perror("socket()");
				exit(errno);
		}

		hostinfo = gethostbyname(address);
		if (hostinfo == NULL)
		{
				fprintf (stderr, "Unknown host %s.\n", address);
				exit(EXIT_FAILURE);
		}

		sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
		sin.sin_port = htons(atoi(port));
		sin.sin_family = AF_INET;

		if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
		{
				perror("connect()");
				exit(errno);
		}

		return sock;
}

int main(int argc, char **argv)
{
		if(argc < 3)
		{
				printf("Usage : %s [address] [port] [pseudo]\n", argv[0]);
				return EXIT_FAILURE;
		}
		init();
		app(argv[1], argv[2], argv[3]);
		end();
		return EXIT_SUCCESS;
}

