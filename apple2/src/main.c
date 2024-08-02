/**
 * Reset (launches CONFIG on reboot)
 *
 * @license gpl v. 3, see LICENSE.md for details.
 */

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "fujinet-fuji.h"

void main(void)
{
	bool success;

	clrscr();

	success = fuji_reset();
	if (success)
	{
		printf("Reset succeeded\n");
	}
	else
	{
		printf("Reset failed\n");
	}

	while (1) {}
};
