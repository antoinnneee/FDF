#include "../fdf.h"
#include "../GNL_NOFD/get_next_line.h"


void	get_next_number(char *line, int **nbr, t_init	*t_size)
{
	int	i;
	int	j;
	int	num;
	int	*count;
	int	*tmp;

	i = 0;
	*count = 0;
	while(line[i] != 0)
	{
		if (!ft_isdigit(line[i]) && i > 0)
		{
			if (*count == 0)
				*nbr = (int*)ft_memalloc(*count+1);
			else
			{
				ft_memmove(tmp, nbr, *count + 1);
				*nbr = (int*)ft_memalloc(*count+1);
				ft_memmove(nbr, tmp, *count + 1);
			}
			*nbr[*count] = ft_atoi(ft_strsub(line, j, i - j));
			*count = *count + 1;
		}
		else if(ft_isdigit(line[i]))
		{
			i++;
			j = i;
		}
		else
			i++;
	}
	t_size->nbr_col_end = &count;
}

t_init	count_nbr(int fd)
{
	t_init	t_size;
	int		**tabnumber;
	int		***ptrtab;
	int		*indexline;
	int		*col;
	char	*line;
	int		**number;
	int		*tmp;

	*indexline = 0;
	ptrtab = &tabnumber;
	col = 0;
	while (get_next_line(fd, &line) == 1)
	{
			if (indexline == 0)
				tabnumber = (int**)ft_memalloc(*indexline + 1);
			else
			{
				ft_memmove(tmp, tabnumber, *indexline + 1);
				tabnumber = (int**)ft_memalloc(*indexline + 1);
				ft_memmove(tabnumber, tmp, *indexline + 1);
			}
		get_next_number(line, &tabnumber[*indexline], &t_size);
		*indexline = *indexline + 1;
	}

	return (t_size);
}
