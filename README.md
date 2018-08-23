# corewar
Corewar is a programming game, where programs (*champions*) with a special set of instructions are executed inside a virtual machine (*vm*).
The *champions* utilize these instructions to compete for the vm's memory and ultimately defeat their opponents.

![Progress](https://github.com/yunusabd/corewar/raw/master/resources/Debug.gif "Progress")

At the beginning of the game, each *champions* code gets loaded into the vm at equal distance from each other. Then the vm places a process at the beginning of the code of each champion. The process moves through the code and executes the instructions.

All the possible instructions, along with their corresponding parameters, can be seen in this array, in the following order:
Name of the operation, number of parameters, types of parameters, opcode, description, encoding byte yes\no, half size yes\no.

```
t_op    g_op_tab[17] =
{
    {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index", 1, 1},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index", 1, 1},
    {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index", 1, 1},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
    {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
    {0, 0, {0}, 0, 0, 0, 0, 0}
};
```
