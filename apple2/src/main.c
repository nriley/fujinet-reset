/**
 * Reset (launches CONFIG on reboot)
 *
 * @license gpl v. 3, see LICENSE.md for details.
 */

#include <stdio.h>
#include <conio.h>
#include "fujinet-fuji.h"

void main(void)
{
	clrscr();

	if (!fuji_reset())
	{
		printf("Resetting FujiNet failed.\n");
		while (1)
			;
	}

	printf("FujiNet reset succeeded.\n");
	printf("Rebooting into CONFIG...\n");
	__asm__("lda #$0");
	__asm__("sta $3f4");	/* reset power-up byte */
	__asm__("jmp ($fffc)"); /* reset */
}
