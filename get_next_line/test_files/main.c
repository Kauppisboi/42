/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jere.rignell@aalto.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:57:04 by jrignell          #+#    #+#             */
/*   Updated: 2019/11/06 17:47:27 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *line1;
	int		fd;
    int     fd1;
    int     fd2;
	char	buf[1];

///*
//	read(0, &buf, 1);
	buf[0] = '1';
	fd = 0;
	fd1 = 0;
	fd2 = 0;
    if (argc == 1)
	{
		while (get_next_line(fd, &line1) > 0)
		{
			printf("%s\n", line1);
			free(line1);
		}

	}
	else if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 < 0)
		{
			printf("There was an error.\n");
			return (-1);
		}
		while (get_next_line(fd1, &line1) > 0)
		{
			printf("%s\n", line1);
			free(line1);
		}


		if (get_next_line(fd1, &line1) == 0)
			printf("~~~~File read.~~~~~\n\n");
		free(line1);

	}
	else if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		if (fd2 < 0 || fd1 < 0)
		{
			printf("\nThere was an error.\n\n");
			return (-1);
		}
		
		get_next_line(fd1, &line1);
		printf("%s\n", line1);
		free(line1);
		get_next_line(fd2, &line1);
		printf("%s\n", line1);
		free(line1);
		
		get_next_line(fd1, &line1);
		printf("%s\n", line1);
		free(line1);
        get_next_line(fd2, &line1);
        printf("%s\n", line1);
		free(line1);
	}
	/*	~~~~~~~~BONUS~~~~~~~~~~~					*/
	/*	~~~~~~~~PART~~~~~~~~~~~~					*/
	else if (argc == 4)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd = open(argv[3], O_RDONLY);

		get_next_line(fd1, &line1);
		printf("%s\n", line1);
		free(line1);
		get_next_line(fd2, &line1);
		printf("%s\n", line1);
		free(line1);
		get_next_line(fd1, &line1);
		printf("%s\n", line1);
		free(line1);

		get_next_line(fd, &line1);
		printf("%s\n", line1);
		free(line1);
		get_next_line(fd2, &line1);
		printf("%s\n", line1);
		free(line1);
	}
//	read(0, &buf, 1);
    close(fd1);
	close(fd2);
	close(fd);
    return (0);
}
