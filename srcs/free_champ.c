/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:27:19 by yabdulha          #+#    #+#             */
/*   Updated: 2018/07/26 14:29:18 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_champ(t_champ *champ)
{
	free(champ->file_name);
	free(champ->name);
	//TODO Free bytes list
	free(champ);
}
