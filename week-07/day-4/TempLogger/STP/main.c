#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rs232/rs232.h"
#include "printer.h"
#include "parser.h"

int main()
{
	int logging_is_running = 0;
	comEnumerate();
	print_startup_message();

	while (1) {
		if (kbhit()) {
			char key = getch();
			switch (key) {
			case 'h':
				print_startup_message();
				break;
			case 'l':
				print_port_list();
				break;
			case 'p':
				get_port_name();
				break;
			case 'o':
				open_port();
				break;
			case 's':
				if (logging_is_running) {
					logging_is_running = 0;
					printf("Logging stopped\n");
				} else {
					logging_is_running = 1;
					printf("Logging started\n");
				}
				break;
            case 'k':
                clear_screen();
				print_log();
				break;
			case 'a':
			    clear_screen();
				avarage_by_days();
				print_startup_message();
				break;
			case 'c':
				close_port();
				break;
			default:
				break;
			}

			if (key == 'e')
				break;
		}
		if (logging_is_running) {
			if (log_data() != 0) {
				printf("Logging error.\n");
				printf("Logging stopped\n");
				logging_is_running = 0;
			}
		}
	}

	comTerminate();
	return 0;
}

void avarage_by_days(){
    print_daily_avarage_message();
    while (1) {
		if (kbhit()) {
			char key = getch();
			switch (key) {
			case '1':
				printf("1.");
				break;
			case '2':
				printf("2.");
				break;
			case '3':
				printf("3.");
				break;
			}
			if (key == 'e')
				break;
		}
    }
}
