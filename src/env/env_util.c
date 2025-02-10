#include "env.h"

char	*extract_key_plus(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '+');
	return (ft_substr(line, 0, len));
}
