#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
/* 	int ccc;
	int fd;
	ssize_t r;

	fd = open("resources/champs/42.cor", O_RDONLY);
	if (fd < 0){
		write(1, "kaka\n", 5);
		return 0; 
	}
	r = read(fd, &ccc, 4);
	if (r < 0) {
		write(1, "keke\n", 5);
		return 0; 
	}
	ft_printf("magic: %d\n", ccc);
	ft_printf("magic: %#x\n", ccc);

	printf("magic: %d\n", ccc);
	printf("magic: %#x\n", ccc); */

	t_vec *buffer;
	int i;

	// buffer = ft_vnew(10, sizeof(char*));
	// for (i = 0; i < 10; i++) {
	// 	ft_vpush_back(buffer, "kek\n", size_t)
	// }
	return 0;
}