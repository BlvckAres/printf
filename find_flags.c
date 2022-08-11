#include "main.h"

/**
 * find_flags - calcs active flags
 * @sett: settted string in which to print the arguments
 * @y: take a parameter.
 * Return: flags:
 */
int find_flags(const char *sett, int *y)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, preset;
	int flags = 0;
	const char flags_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (preset = *y + 1; sett[preset] != '\0'; preset++)
	{
		for (m = 0; flags_CH[m] != '\0'; m++)
			if (sett[preset] == flags_CH[m])
			{
				flags |= flags_ARR[m];
				break;
			}

		if (flags_CH[m] == 0)
			break;
	}

	*y = preset - 1;

	return (flags);
}
