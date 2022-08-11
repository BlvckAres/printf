#include "main.h"

/**
 * find_flags - Calculates active flags
 * @sett: settted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int find_flags(const char *sett, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, preset;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (preset = *i + 1; sett[preset] != '\0'; preset++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (sett[preset] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = preset - 1;

	return (flags);
}
