
rm -f Makefile


if [ "$1" == "" ]
then
	echo "usage : ./Makefile.sh   executable_name   Use_libft[0 | 1 | 2 = mlx (42 only) + lft]   FlagOption[0 = noflag | 1 = normal | 2 = debug] "
else
	RM="rm -f"
	LAST=$(date "+%Y/%m/%d %H:%M:%S")
	CREAT="Created: $LAST by abureau"
	UPDATE="Updated: $LAST by abureau"
################################### HEADER #####################################
echo "#******************************************************************************#" >> Makefile
echo "#                                                                              #" >> Makefile
echo "#                                                         :::      ::::::::    #" >> Makefile
echo "#    Makefile                                           :+:      :+:    :+:    #" >> Makefile
echo "#                                                     +:+ +:+         +:+      #" >> Makefile
echo "#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #" >> Makefile
echo "#                                                 +#+#+#+#+#+   +#+            #" >> Makefile
echo "#    $CREAT           #+#    #+#              #" >> Makefile
echo "#    $UPDATE          ###   ########.fr        #" >> Makefile
echo "#                                                                              #" >> Makefile
echo "#******************************************************************************#" >> Makefile
################################# ~HEADER #####################################

################################## SRC  #######################################
	echo "\nNAME = $1" >> Makefile
	INDEX=0
	NBRFILES=-1
	TAB='\x09'
	if [ "$2" == "0" ]
	then
		CFILES=$(find . -name "*.c")
	else
		CFILES=$(find . -name "*.c" | grep -v "libft")
	fi

	for FILES in $CFILES
	do
			let "NBRFILES = NBRFILES + 1"
	done
	for FILES in $CFILES
	do
		if [ "$NBRFILES" == "0" ]
		then
				echo "\nSRC = $FILES" >> Makefile
		else
			if [ "$INDEX" == "0" ]
			then
				echo "\nSRC = $FILES \\" >> Makefile
			elif [ "$INDEX" == "$NBRFILES" ]
			then
				echo "$TAB$FILES" >> Makefile
			else
				echo "$TAB$FILES \\" >> Makefile
			fi
		fi
			let "INDEX = INDEX + 1"
	done
################################## ~SRC  ######################################

################################# FLAGS #######################################
	if [ "$3" == "1" ]			## NORMOL
	then
		echo "\nCC = gcc\n\nOBJ = \$(SRC:.c=.o)\n\nCFLAGS = -Wall -Werror -Wextra" >> Makefile
	elif [ "$3" == "2" ]		## DEBUG
	then
		echo "\nCC = gcc\n\nOBJ = \$(SRC:.c=.o)\n\nCFLAGS = -g -Wall -Wextra" >> Makefile
	else						## NOFLAG
		echo "\nCC = gcc\n\nOBJ = \$(SRC:.c=.o)\n\nCFLAGS = " >> Makefile
	fi
################################# ~FLAGS ######################################

################################ COMPILE ######################################
	if [ "$2" == "1" ]			## USE LIB
	then
		echo "\nall: LIBCOMPILE \$(NAME)\n\n\$(NAME): \$(OBJ)" >> Makefile
		echo "$TAB\$(CC) -o \$@ \$^ -I libft/includes -L libft/ -lft" >> Makefile
		echo "\nLIBCOMPILE:\n$TAB make -C libft/" >> Makefile
		echo "\n%.o: %.c\n$TAB\$(CC) \$(CFLAGS) -I libft/includes -o \$@ -c \$<" >> Makefile
	echo "\nclean:\n$TAB$RM \$(OBJ)\n$TAB make -C libft/ clean" >> Makefile
	echo "\nfclean: clean\n$TAB$RM \$(NAME)\n$TAB make -C libft/ fclean" >> Makefile
	elif [ "$2" == "2" ]		## LIB + MLX
	then
		echo "\nall: LIBCOMPILE \$(NAME)\n\n\$(NAME): \$(OBJ)" >> Makefile
		echo "$TAB\$(CC) -o \$@ \$^ -I libft/includes -L libft/ -lft -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit" >> Makefile
		echo "\nLIBCOMPILE:\n$TAB make -C libft/" >> Makefile
		echo "\n%.o: %.c\n$TAB\$(CC) \$(CFLAGS) -I libft/includes -o \$@ -c \$<" >> Makefile
	echo "\nclean:\n$TAB$RM \$(OBJ)\n$TAB make -C libft/ clean" >> Makefile
	echo "\nfclean: clean\n$TAB$RM \$(NAME)\n$TAB make -C libft/ fclean" >> Makefile
	else						## NOTHING
		echo "\nall: \$(NAME)\n\n\$(NAME): \$(OBJ)" >> Makefile
		echo "$TAB\$(CC) -o \$@ \$^" >> Makefile
		echo "\n%.o: %.c\n$TAB\$(CC) \$(CFLAGS) -o \$@ -c \$<" >> Makefile
	echo "\nclean:\n$TAB$RM \$(OBJ)" >> Makefile
	echo "\nfclean: clean\n$TAB$RM \$(NAME)" >> Makefile
	fi
	echo "\nre: fclean all" >> Makefile
fi
############################### ~COMPILE ######################################

cat Makefile
