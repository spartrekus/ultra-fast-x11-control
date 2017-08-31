
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_MAX 250
#include <ncurses.h>
#include "../lib/libncurse.c"

void drawit( int pagego )
{
     int rows, cols;  
     getmaxyx( stdscr, rows, cols);
     mvprintw(5 , 5, "NSHOWKEY !!!");	
     if ( pagego >= 1 )
       mvprintw(7 , 5, "INFO KEY: %d-DEC" , pagego );
     mvprintw(rows-1 , 0, "<Press Key to Continue (hjkl)>");

}



int main()
{	
        int ch ;  int gameover = 0;
	initscr();			/* Start curses mode 		  */
        curs_set( 0 );

        char charo[PATH_MAX]; 
        int fooint ; 

        erase();
        drawit( 0 );

        while( gameover == 0 ){
	  ch = getch();			/* Wait for user input */
          erase();
          drawit( ch );
	  refresh();			/* Print it on to the real screen */
        }

        curs_set( 1 );
	endwin();			/* End curses mode		  */
	return 0;
}


