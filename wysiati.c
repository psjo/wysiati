#include <ncurses.h>
#include <stdio.h>

static const WINDOW *w;

int looping(void)
{
	int ch;
        int x, y;
	
	for (;;) {
		
		ch = getch();
		switch (ch)
		{	
		case KEY_F(10):
			//dirty/encrypt
			return 0;
			break;	
		case KEY_LEFT:
			
			break;
		case KEY_RIGHT:
			
			break;
		case KEY_UP:
			
			break;
		case KEY_DOWN:
			
			break;
		case 127:
		case 8:
                        printw("%c", ch);
                        break;
                case 263:
                        //getyx(w, x, y);
			printw("%c", 8);
			//printw("%d %d", x, y);
			break;
		default:
			//attron(A_BOLD);
			printw("%c", ch);
			//attroff(A_BOLD);
		}
		
		refresh();			/* Print it on to the real screen */
	}
	
	//getch();			/* Wait for user input */

	return 1;
}

int main()
{
	w = initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */
	curs_set(1);        /* cursor wiz */
	
	printw("\twysiati (F10 to exit)\n");
	looping();
	endwin();			/* End curses mode		  */
	
	return 0;
}
