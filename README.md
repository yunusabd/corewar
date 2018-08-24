# corewar
Corewar is a programming game, where programs (*champions*) with a special set of instructions are executed inside a virtual machine (*vm*).
The champions utilize these instructions to compete for the vm's memory and ultimately defeat their opponents.

![Progress](https://github.com/yunusabd/corewar/raw/master/resources/Debug.gif "Progress")

At the beginning of the game, each champions' code gets loaded into the vm at equal distance from each other. The vm then places a process at the beginning of the code of each champion. The process moves through the code and executes the instructions. Instructions have different 'costs' measured in execution cycles. The most powerful of the instructions, *lfork*, takes 1000 cycles before execution, time in which the process is dormant and not doing anything. While creating a champion, this is one aspect to take into consideration.

Each process has at its disposal a number of *registers*, that it can use to store data (by default 16 registers à 4 bytes). The first of these registers holds the player number assigned by the vm. For example, a process can copy its player number into the vm, to call *live* for that player:

In terms of bytecode, it would look like this: ```03 70 01 00 06 01 00 00 00 00```
- ```03``` is the opcode for *st* or *store*, which writes bytes from the register into the vm or into another register.
- ```70``` is the encoding byte, which stores information about the type of parameters. ```70``` in hex is ```0111 0000``` in binary, that gets interpreted from the left 2 bits at a time. So the first parameter is ```01```, which means register, the second is ```11```, which means indirect. In this case, there is no third parameter, and in no case there is a fourth parameter.
- ```01``` is the register to read from
- ```00 06``` is the indirect value to write to, in relation to the position of the program counter, which is at 03.

The process sleeps for 5 cycles and then writes the number from its register ```01``` into position ```00 06``` after the program counter. If we assume the player number to be 3, that part of the memory will look like this: ```03 70 01 00 06 01 00 00 00 03```

The process then jumps to the next instruction ```01```, *live*. Live doesn't have an encoding byte, it just takes one direct parameter. So, the process will sleep for 10 cycles and then call live for player 3, which is itself. Note that any program counter landing on that particular instruction will call *live* for that player. Conversely, it is also possible to change the first register of any process, if you have an instruction for that in the vm and the process lands on that.

While at the beginning each champion has only one process, there are instructions to clone a process and create multiple processes, which inherit their parents' registers.

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
