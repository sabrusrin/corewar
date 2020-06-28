#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


typedef unsigned char uchar;
typedef unsigned int uint;

void	print_binary_uint(uint n)
{
	uint mask;
	int i;

	mask = 1 << 31;
	i = 0;
	while (mask)
	{
		if (n & mask)
			printf("1");
		else
			printf("0");
		i++;
		if (i % 4 == 0)
			printf(" ");
		mask >>= 1;
	}
	printf("\n");
}


uint 	reverse_byte_by_byte_int(uint num)
{
	uint	rev;
	uint	factor;
	// uchar	mask;
	
	// mask = num & 0xff;
	// factor = 16 * 16 * 16;
	// rev = 0;
	// printf("%x\n", (num & 0xFF));
	// printf("%x\n", (num & 0xFF) << 24); //the same
	// printf("%x\n\n", (num & 0xFF) * 4096);

	// printf("\n%x\n", num & 0xFF00);
	// printf("%x\n\n", (num & 0xFF00) << 8);

	// printf("%x\n", num & 0xFF0000);
	// printf("%x\n", (num & 0xFF0000) >> 8); //the same
	// printf("%x\n", (num & 0xFF0000) / 256);

	// printf("%x\n", (num & 0xFF000000) >> 24);
	// printf("%x\n", num & 0xFF000000 >> 24);
	rev = ((num & 0xFF) << 24) | ((num & 0xFF00) << 8) | ((num & 0xFF0000) >> 8) | ((num & 0xFF000000) >> 24);
	// rev = (num & 0xFF); // | (num & 0xFF00) | (num & 0xFF0000) | (num & 0xFF000000);
	// while (num)
	// {
	// 	rev = factor * (num & 0xff);
	// 	num = num >> 8;
	// 	factor = factor / 16;
	// }
//	rev = 16 * 16 * 16 * (num & 0xff) + 256 * ((num >> 8) & 0xff) + 16 * ((num >> 16) & 0xff) + ((num >> 24) & 0xff);
	return (rev);
}

int main(int argc, char **argv)
{
	int fd;
	int r;
	uint a;

	// fd = open("ex.cor", O_RDONLY, 0);
	// r = read(fd, &a, 4);
	// r = read(fd, &a, 4);

	a = 0xa1071bcd;
	printf("%x\n", a);

	// print_binary_uint(a);

	// printf("%u\n", r);
	a = reverse_byte_by_byte_int(a);
	// print_binary_uint(a);
	// printf("%u\n", a);
	printf("%x\n", a);



	// close(fd);
	return(0);
}