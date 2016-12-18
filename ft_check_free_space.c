#include "fillit.h"
#include <stdio.h>

static int  ft_find_free_space(int step, int pos, t_square *map, int max)
{
    if (step == 3)
    {
        printf("YES!!!\tposition is %d\n%s\n", pos, map->str);
        return (1);
    }
    map->str[pos] = '1';
    printf("step is %d\n", step);
    if (pos - 1 >= 0 && map->str[pos - 1] == '.')
    {
        if (ft_find_free_space(step + 1, pos - 1, map, max) == 1)
            return (1);
    }
    if (pos - map->size - 1 >= 0 && map->str[pos - map->size - 1] == '.')
    {
        if (ft_find_free_space(step + 1, pos - map->size - 1, map, max) == 1)
            return (1);
    }
    if (pos + 1 <= max && map->str[pos + 1] == '.')
    {
        if (ft_find_free_space(step + 1, pos + 1, map, max) == 1)
            return (1);
    }
    if (pos + map->size + 1 <= max && map->str[pos + map->size + 1] == '.')
    {
        if (ft_find_free_space(step + 1, pos + map->size + 1, map, max) == 1)
            return (1);
    }
    return (0);
}

int         ft_check_free_space(t_square *map, int last_elem)
{
    int pos;
    int last_pos;

    pos = -1;
    last_pos = (int)ft_strlen(map->str) - 2;
    while (++pos <= last_elem)
    {
//        printf("##########\npos = %d\n%s\n",pos, map->str);
        if (map->str[pos] == '.')
        {
            if (ft_find_free_space(0, pos, map, last_pos) == 0)
            {
                ft_clear(map->str, '1');
                return (0);
            }
            else
                ft_clear(map->str, '1');
        }
    }
//    printf("result OK\tmap\n%s\n", map->str);
    return (1);
}
