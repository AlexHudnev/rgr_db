/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "rgr.pgc"
#include <iostream>

#line 1 "/usr/include/postgresql/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif							/* __CYGWIN__ */
#endif							/* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern "C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 2 "rgr.pgc"

using namespace std;

void set_error_handler()
{
    /* exec sql whenever sqlerror  call error_handler ( ) ; */
#line 7 "rgr.pgc"

}
void error_handler()
{
	cout << "***** Error : " << sqlca.sqlerrm.sqlerrmc;
	exit(-1);
}
void connectionToDb(const char* host, const char* dbname, const char* user, const char* pass) {
	/* exec sql begin declare section */
		 
		    
		    
		    
	
#line 16 "rgr.pgc"
 char target [ 256 ] ;
 
#line 17 "rgr.pgc"
 const char * db = dbname ;
 
#line 18 "rgr.pgc"
 const char * u = user ;
 
#line 19 "rgr.pgc"
 const char * p = pass ;
/* exec sql end declare section */
#line 20 "rgr.pgc"


	strcpy(target, db);
	strcat(target, "@");
	strcat(target, host);

	cout << "target: " << target << endl;

	{ ECPGconnect(__LINE__, 0, target , u , p , NULL, 0); 
#line 28 "rgr.pgc"

if (sqlca.sqlcode < 0) error_handler ( );}
#line 28 "rgr.pgc"

}

#include "country.c"
#include "state.c"
#include "city.c"
#include "passenger.c"
#include "trip.c"
#include "transport_route.c"

void menu() {
	while (true) {
		cout << "Меню:" << endl;
		cout << "1. Управление странами:" << endl;
		cout << "2. Управления Административными единицами" << endl;
		cout << "3. Управление городами" << endl;
		cout << "4. Управление пассажирами" << endl;
    cout << "5. Управление поездками" << endl;
    cout << "6. Управление транспортными маршрутами" << endl;
		cout << "0. Выход" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				menu_country();
				break;
			}
			case 2: {
				menu_state();
				break;
			}
			case 3: {
				menu_city();
				break;
			}
			case 4: {
				menu_passenger();
				break;
			}
      case 5: {
      menu_trip();
      break;
      }
      case 6: {
       menu_transport_route();
       break;
       }
			case 0: {
				return;
			}
		}
	}
	return;
}

int main() {
	set_error_handler();

	connectionToDb("localhost", "rgr", "alex", "1111");

	menu();

	return 0;
}
