
#include "../include/libft.h"
	
int	ft_printf_arg(const char *c, int i, va_list args)
{
    if (c[i + 1] == '%')
        return (ft_putchar(c[i + 1]));
    else if (c[i + 1] == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (c[i + 1] == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (c[i + 1] == 'd' || c[i + 1] == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (c[i + 1] == 'u')
        return (putnbr_u(va_arg(args, unsigned int)));
    else if (c[i + 1] == 'x' || c[i + 1] == 'X')
    {
        if (c[i + 1] == 'X')
            return (put_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
        else
            return (put_hex(va_arg(args, unsigned int), "0123456789abcdef"));
    }
    else if (c[i + 1] == 'p')
        return (ft_putstr("0x") + put_pointer(va_arg(args, void *), \
                "0123456789abcdef"));
    else
        return (0);
}

int    ft_printf(const char* c, ...)
{   
    int i;
    int cont;
    va_list args;
    
    i = 0;
    cont = 0;
    va_start(args, c);
 
    while (c[i] != '\0')
    {
        if (c[i] == '%' && ft_strchr("cspdiuxX%", c[i + 1]))
        {
            cont += ft_printf_arg(c, i, args);
            i++;
        }
        else   
            cont = ft_putchar(c[i]);
        i++;
    }

    va_end(args);
    return (cont);
}

int main()
{   
    char c = 'a';

    //printf("%c %c\n", c);

    ft_printf(&c);

    return (0);    
}
