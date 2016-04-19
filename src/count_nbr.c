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
	j = 0;
	count = (int*) malloc(sizeof(int));
	*count = 0;
	while(line[i] != 0)
	{
		if (!ft_isdigit(line[i]) && i > 0)
		{
			if (*count == 0)
				*nbr = (int*)malloc(sizeof(int) * (*count+1));
			else
			{
				tmp = (int*)malloc(sizeof(int) * (*count+1));
				ft_memmove(tmp, nbr, *count + 1);
				*nbr = (int*)malloc(sizeof(int) * (*count+1));
				ft_memmove(nbr, tmp, *count + 1);
				free(tmp);
			}
			*nbr[*count] = ft_atoi(ft_strsub(line, j, i - j));
			*count = *count + 1;
		}
		else if(ft_isdigit(line[i]))
		{
			j = i;
			i++;
		}
		else
			i++;
	}
	t_size->nbr_col_end = &count;
}

t_init	count_nbr(int fd)
{
	ft_putstrnb("fd : ", fd);
	t_init	t_size;
	int		**tabnumber;
	int		***ptrtab;
	int		*indexline;
	int		*col;
	char	*line;
	int		**number;
	int		**tmp;

	ft_putendl("begin count_nbr");
	indexline = ft_memalloc(1);
	*indexline = 0;
	ptrtab = &tabnumber;
	col = 0;
	while (get_next_line(fd, &line) == 1)
	{
	ft_putendl("begin gnl loop");
			if (*indexline == 0)
				tabnumber = (int**)malloc(*indexline + 1);
			else
			{
				tmp = (int**)malloc(sizeof(int*) * (*indexline + 1));
				ft_memmove(tmp, tabnumber, *indexline + 1);
				tabnumber = (int**)malloc(sizeof(int*) * (*indexline + 1));
				ft_memmove(tabnumber, tmp, *indexline + 1);
				free (tmp);
				tmp = NULL;
			}
		get_next_number(line, &tabnumber[*indexline], &t_size);
		ft_putendl("print number :");
		ft_putnbrnl(tabnumber[*indexline][0]);
		*indexline = *indexline + 1;
	}

	return (t_size);
}
