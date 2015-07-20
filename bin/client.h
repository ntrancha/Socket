/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 15:39:30 by ntrancha          #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

static void app(const char *address, const char *port, const char *name);
static int init_connection(const char *address, const char *port);

#endif /* guard */

