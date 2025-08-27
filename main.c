//
//  main.c
//  get_next_line
//
//  Created by Faruk Kuz on 7.08.2025.
//

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;
	char	*str2;
	char	*str3;
	char	*str4;

	fd = open("sus.txt", O_CREAT | O_RDWR, 0777);
	str = get_next_line(fd);
	printf("%s\n", str);
	str2 = get_next_line(fd);
	printf("%s\n", str2);
	str3 = get_next_line(fd);
	printf("%s\n", str3);
	str4 = get_next_line(fd);
	printf("%s\n", str4);
	close(fd);
	return (0);
}
