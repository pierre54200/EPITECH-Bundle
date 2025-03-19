/*
** EPITECH PROJECT, 2024
** count_island
** File description:
** count the nmb of island
*/
void put_every_next_nb3(char **world, int x, int y)
{
    if (world[x + 1] != 0 && world[x + 1][y] >= '0'
        && world[x + 1][y] <= '9' && world[x][y] != '.')
        world[x][y] = world[x + 1][y];
    if (world[x][y + 1] != 0 && world[x][y + 1] >= '0'
        && world[x][y + 1] <= '9' && world[x][y] != '.')
        world[x][y] = world[x][y + 1];
    return;
}

void put_every_next_nb2(char **world, int x, int y)
{
    if (y > 0 && world[x][y - 1] >= '0'
        && world[x][y - 1] <= '9' && world[x][y] != '.')
        world[x][y] = world[x][y - 1];
    if (x > 0 && world[x - 1][y] >= '0'
        && world[x - 1][y] <= '9' && world[x][y] != '.')
        world[x][y] = world[x - 1][y];
    put_every_next_nb3(world, x, y);
    return;
}

void put_every_next_nb(char **world)
{
    for (int x = 0; world[x] != 0; x++) {
        for (int y = 0; world[x][y] != 0; y++)
            put_every_next_nb2(world, x, y);
    }
    for (int x = 0; world[x] != 0; x++) {
        for (int y = 0; world[x][y] != 0; y++)
            put_every_next_nb3(world, x, y);
    }
    for (int x = 0; world[x] != 0; x++) {
        for (int y = 0; world[x][y] != 0; y++)
            put_every_next_nb2(world, x, y);
    }
    return;
}

int put_first_nb(char **world, int x, int y, char nb)
{
    if (world[x][y] == 'X') {
        world[x][y] = nb;
        put_every_next_nb(world);
        put_every_next_nb(world);
        return nb + 1;
    }
    return nb;
}

int count_island(char **world)
{
    char nb = '0';

    for (int x = 0; world[x] != 0; x++) {
        for (int y = 0; world[x][y] != 0; y++)
            nb = put_first_nb(world, x, y, nb);
    }
    nb = nb - '0';
    return nb;
}
