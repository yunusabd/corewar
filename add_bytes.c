/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:59:08 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 11:27:35 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			add_byte(t_byte *head, char c)
{
	t_byte	*tmp;
	t_byte	*new;

	if (!(new = (t_byte*)malloc(sizeof(t_byte))))
		exit(1);
	//add error handler function
	new->byte = c;
	new->next = NULL;
	tmp = head;
	if (!tmp)
		head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}


/*
**	Create a struct for each byte read from the input file. Return pointer to
** 	the beginning of the list to store in champ struct.
*/

void			read_bytes(t_champ champ, char *buff, t_byte *head)
{
	t_byte	*tmp;

	while (buff)
	{
		add_byte(head, *buff);
		buff++;
	}
}
