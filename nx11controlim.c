
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
     mvprintw(5 , 5, "NX11CONTROL !!!");	
     mvprintw(rows-1 , 0, "<Press Key to Continue (hjkl)>");
}




int main()
{	
        int ch ;  int gameover = 0;
	initscr();			/* Start curses mode 		  */
        curs_set( 0 );

        char charo[PATH_MAX]; 
        int fooint ; 

        while( gameover == 0 ){

        drawit( 0 );

	refresh();			/* Print it on to the real screen */

	ch = getch();			/* Wait for user input */


        if ( ch == 40 ) // this is (
           nruncmd( " xdotool key Left " );  //for feh
        else if ( ch == 41 ) // this is ) 
           nruncmd( " xdotool key Right " );  //for feh

        else if ( ch == 16 )  // ctrl+p (for par)
           nruncmd( "  wmctrl -r :ACTIVE: -b toggle,maximized_vert,maximized_horz   " );

        else if ( ch == 24 )  // ctrl+x 
           nruncmd( " xdotool key ctrl+x " ); 
        else if ( ch == 23 )  // ctrl+w
           nruncmd( " xdotool key ctrl+w " ); 

        else if ( ch == 10 ) 
           nruncmd( " xdotool key Return " ); 
        else if ( ch == 13 ) 
           nruncmd( " xdotool key Return " ); 

        else if ( 
           (( ch >= 'a' ) && ( ch <= 'z' ))
        || (( ch >= '1' ) && ( ch <= '9' ))
        || (( ch >= 'A' ) && ( ch <= 'Z' ))
        || ( ch == '0' ) 
        )
        {
           fooint = snprintf( charo, 100 , " xdotool key %c ", ch );
           printf( "[BEGIN CMD: %s\n" , charo );
           nruncmd( charo  );
           printf( "END CMD: %s]\n" , charo );
        }
        else switch( ch )
        {
           case 13:
              nruncmd( " xdotool key Return " ); 
              break;
           case 4: //ctrl+d
              nruncmd( " xdotool key Page_Down " ); 
              break;
           case 21: //ctrl+u
              nruncmd( " xdotool key Page_Up " ); 
              break;


           case 27:
              nruncmd( " xdotool key Escape " ); 
              break;

           case 32:
              nruncmd( " xdotool key space " ); 
              nruncmd( " xdotool key Space " );  // will not work
              break;

           case 126:
              nruncmd( " xdotool key Delete " ); 
              break;

           case 127:
              nruncmd( " xdotool key BackSpace " ); 
              break;

       /*
            65
        68  66  67
       */

           case 68:
              nruncmd( " xdotool key Left " ); 
              break;
           case 66:
              nruncmd( " xdotool key Down " ); 
              break;
           case 65:
              nruncmd( " xdotool key Up " ); 
              break;
           case 67:
              nruncmd( " xdotool key Right " ); 
              break; 

           case '+':
              nruncmd( " xdotool key KP_Add " ); 
              break;
           case '-':
              nruncmd( " xdotool key KP_Subtract " ); 
              break;


           // for screen
           //case 93:
           case ']':
              nruncmd( " xdotool key F12 " ); 
              break;
           //case 91:
           case '[':
              nruncmd( " xdotool key F11 " ); 
              break;

   ////[[[[[[ 
        /*
          // extras
           case 'f':
              nruncmd( " xdotool key f " ); 
              break;
           case 'q':
              nruncmd( " xdotool key q " ); 
              break;
           case 'z':
              nruncmd( " xdotool key z " ); 
              break;
           case 'e':
              nruncmd( " xdotool key e " ); 
              break;
           case 'i':
              nruncmd( " xdotool key i " ); 
              break;
           case 'b':
              nruncmd( " xdotool key b " ); 
              break;
           */  ///]]]]]
         }
          
       
        }
        curs_set( 1 );
	endwin();			/* End curses mode		  */
	return 0;
}



//nruncmd( " xdotool key Super_L+w " ); 




