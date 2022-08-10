#include "main.h"

/**
 * find_flags - calculates active flags
 * @sett: formatted string in which to print the args
 * @y: get a parameter.
 * Return: Flags:
 */
int find_flags(const char *sett, int *y)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int m, preset_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (preset_i = *y + 1; sett[preset_i] != '\0'; preset_i++)
	{
		for (m = 0; FLAGS_CH[m] != '\0'; m++)
			if (sett[preset_i] == FLAGS_CH[m])
			{
				flags |= FLAGS_ARR[m];
				break;
			}

		if (FLAGS_CH[m] == 0)
			break;
	}

	*y = preset_i - 1;

	return (flags);
}
