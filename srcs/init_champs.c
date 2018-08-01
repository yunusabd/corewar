#include "vm.h"

void	load_champ(t_vm *vm, t_champ *champ)
{
	int	i;
	int	j;

	i = 0;
	printf("loading champ..\n");
	j = (sizeof(champ->data[1]) * 8);
	while (j >= 0)
	{
		printf("%d ", ((champ->data[1] >> j) & 1) ? 1 : 0);
		j--;
	}
	printf("[%.2x]", champ->data[1]);
	printf("\nended loading\n");
}

void	init_champs(t_vm *vm)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp)
	{
		load_champ(vm, tmp);
		tmp = tmp->next;
	}
}
