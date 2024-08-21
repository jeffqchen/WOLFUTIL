#include <dos.h>
#include <stdlib.h>
#include <stdio.h>

typedef char BYTE;

void interrupt mine(...);
void interrupt (*prev)(...);

BYTE far * videoSwitch = (BYTE far *)MK_FP(0xC000,0xB600);
BYTE far * watchdog    = (BYTE far *)MK_FP(0xC000,0xB201);

int ticks = 0;

void main(int argc, char *argv[])
{
	*watchdog = 0xFF;

	if (argc == 1)
	{
		prev = getvect(8);

		if (60 != (int)prev)
		{
			printf("TSR already loaded or cannot be loaded. Exiting...\n");
			exit(1);
		}

		printf("Taito Wolf System DOS Utility by Jeff Chen, 2024.\n\n");
		printf("Switching to Voodoo output and starting TSR watchdog.\n");

		*videoSwitch = 0x30;

		setvect(8, mine);
		keep(0, 400);

		return;
	} else {
		if ((argv[1][0] == '-' || argv[1][0] == '/') && (argv[1][2] == '\0'))
		{
			switch (argv[1][1])
			{
				case '1':
				case 'v':
				case 'V':
					printf("Switched to Voodoo output.\n");
					*videoSwitch = 0x30;
					return;
				case '0':
				case 's':
				case 'S':
					printf("Switched to splash screen.\n");
					*videoSwitch = 0x0;
					return;
				case '2':
				case 't':
				case 'T':
					printf("Switched to test pattern grid.\n");
					*videoSwitch = 0x2;
					return;
				case '\?':
				case 'h':
				case 'H':
					printf("Taito Wolf System DOS Utility by Jeff Chen, 2024.\n\n");
					printf("==== Help Information ====\n");
					printf("No parameter - load TSR watchdog.\n\n");
					printf("List of possible switches:\n");
					printf("	0/s/S	Show splash screen.\n");
					printf("	1/v/V   Switch to Voodoo output.\n");
					printf("	2/t/T   Show test pattern grid.\n");
					printf("	\?/h/H   This help message.\n");
					return;
			}
		}
	}
	printf("Wrong parameter specified. Please refer to help with -h, -H, /h, /H or /?.\n");

	return;
}

void interrupt mine(...)
{
	ticks++;

	if (ticks == 18)
	{
		*watchdog = 0xFF;
		ticks = 1;
	}

	(*prev)();
}
