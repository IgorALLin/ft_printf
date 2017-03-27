#include "includes/ft_printf.h"

int	main()
{
	int len;
	len = ft_printf("% 4.5i", 42);
	len = printf("\nlen = %d\n", len);
	return (0);
}
