#include <ncurses.h>
//#include <stdio.h>
#include <locale.h>
#include <stdint.h>

static const WINDOW *w;
static int row;
static int col;

static void mover(int y, int x) {
        int posx, posy;

        getyx(w, posy, posx);
        x += posx;
        y += posy;
        if (x < 0) {
                y -= 1;
                x = col - 1;
        } else if (x == col) {
                x = x%col;
                y += 1;
        }
        if (y == row) {
                y = y%row;
        } else if (y < 0)
                y = row - 1;

        move(y, x);
        //printw("%d %d", posx, posy);
}

static void capitalprint(uint64_t c) {
        if (c >= 'a' && c <= 'z')
                printw("%c", c-32);
        else
                printw("%c", c);
        /*
        else if (c == 0xc3a5)
                printw("Å");
        else if (c == 0xc3a4)
                printw("Ä");
        else if (c == 0xc3b6)
                printw("Ö");
                */
}

static int looping(void)
{
	uint64_t ch;
	
	for (;;) {
		
		ch = getch();
		switch (ch)
		{	
		case KEY_F(10): // EXIT
			return 0;
			break;	
		case KEY_F(1): // clear
                        clear();
			break;	
		case KEY_LEFT:
		        mover(0, -1);	
			break;
		case KEY_RIGHT:
			mover(0, 1);
			break;
		case KEY_UP:
			mover(-1, 0);
			break;
		case KEY_DOWN:
			mover(1, 0);
			break;
		case 8:                         // different backspaces
                case 263:
		case 127:
			printw("%c", 8);
			printw(" ");
			printw("%c", 8);
			break;
		default:
                        capitalprint(ch);
			//attron(A_BOLD);
			//printw("0x%lx", ch);
			//attroff(A_BOLD);
		}
		
		refresh();			/* Print it on to the real screen */
	}
	
	//getch();			/* Wait for user input */

	return 1;
}

int main()
{
        setlocale(LC_ALL, "");
	w = initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */
	curs_set(1);        /* cursor wiz */
        getmaxyx(w, row, col);

	//printw("\twysiati (F10 to exit)%d %d\n", row, col);
	looping();
	endwin();			/* End curses mode		  */
	
	return 0;
}
