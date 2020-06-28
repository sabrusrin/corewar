
/*
** we read 1-2-3 arguments depending on opcode and size of 
** its arguments
*/

void	read_arguments(int fd, uchar opcode, uchar arg_size)
{
	int		r;
	uchar	arg1;
	uchar	arg2;
	uchar	arg3;
	uchar b; //bytes for a given argument
...

	arg1 = (arg_size & 0xc0) >> 6;
	arg2 = (arg_size & 0x30) >> 4;
	arg3 = (arg_size & 0xc) >> 2;

	print_binary_uchar(arg1);
	print_binary_uchar(arg2);
	print_binary_uchar(arg3);

	printf("arg1 is %hhu bytes\n", arg_byte(arg_size, arg1));
	printf("arg2 is %hhu bytes\n", arg_byte(arg_size, arg2));
	printf("arg3 is %hhu bytes\n", arg_byte(arg_size, arg3));


/*
RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"
*/


//arg1
...

return ;

//arg2
	b = arg_byte(arg_size, arg2);
	if (b == 1)
		r = read(fd, &f.a1, 1);
	else if (b == 2)
		r = read(fd, &f.a2, 2);
	else if (b == 4)
		r = read(fd, &f.a4, 4);

	f.a2 = reverse_byte_by_byte_short(f.a2);
	printf("2nd arg's r:%d, a2 = %hu\n", r, f.a2);

//arg3
	b = arg_byte(arg_size, arg3);
	printf("3rd arg:%d bytes\n", b);
	if (b == 1)
		r = read(fd, &f.a1, 1);
	else if (b == 2)
		r = read(fd, &f.a2, 2);
	else if (b == 4)
		r = read(fd, &f.a4, 4);
	printf("3rd arg's r:%d, a2 = %hu\n", r, f.a2);

	uchar	arg1;
	arg1 = (arg_size & 0xc0) >> 6;

}
