#include "fillit.h"

static int  ft_find_free_space(int step, int pos, t_square *map, int max)
{
    map->str[pos] = '1';
    if (pos - 1 >= 0 && map->str[pos - 1] == '.')
        step += ft_find_free_space(step + 1, pos - 1, map, max);
    if (pos - map->size - 1 >= 0 && map->str[pos - map->size - 1] == '.')
        step += ft_find_free_space(step + 1, pos - map->size - 1, map, max);
    if (pos + 1 <= max && map->str[pos + 1] == '.')
        step += ft_find_free_space(step + 1, pos + 1, map, max);
    if (pos + map->size + 1 <= max && map->str[pos + map->size + 1] == '.')
        step += ft_find_free_space(step + 1, pos + map->size + 1, map, max);
    return (step);
}

static int  ft_check_prev(t_square *map, int pos, int max)
{
    if (pos - 1 >= 0 && map->str[pos - 1] == '1')
        return (1);
    else if (pos - map->size - 1 >= 0 && map->str[pos - map->size - 1] == '1')
        return (1);
    else if (pos + 1 <= max && map->str[pos + 1] == '1')
        return (1);
    else if (pos + map->size + 1 <= max && map->str[pos + map->size + 1] == '1')
        return (1);
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
        if (map->str[pos] == '.')
        {
            if (ft_check_prev(map, pos, last_pos) == 0)
            {
                if (ft_find_free_space(0, pos, map, last_pos) < 3)
                    return (0);
            }
        }
    }
    return (1);
}
