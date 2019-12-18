/* Processed by ecpg (10.10 (Ubuntu 10.10-0ubuntu0.18.04.1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "passenger.cpp"
/* exec sql whenever sqlerror  sqlprint ; */
#line 1 "passenger.cpp"


void create_passenger() {
	cout << "Введите ФИО пассажира:" << endl;
  string tmpname;
  cin >> tmpname;
  const char* name = tmpname.c_str();

  cout << "Введите номер паспорта:" << endl;
  int passport_id; cin >> passport_id;

	/* exec sql begin declare section */
	    
     

	
#line 13 "passenger.cpp"
 const char * n = name ;
 
#line 14 "passenger.cpp"
 int pid = passport_id ;
/* exec sql end declare section */
#line 16 "passenger.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into passenger ( name , passport_id ) values ( $1  , $2  )", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 17 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 17 "passenger.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 18 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 18 "passenger.cpp"

	return;
}
void show_passenger() {
	cout << "Введите номер паспорта:" << endl;
  int passport_id; cin >> passport_id;

	/* exec sql begin declare section */
     
	  

	
#line 26 "passenger.cpp"
 int pid = passport_id ;
 
#line 27 "passenger.cpp"
 char n [ 256 ] ;
/* exec sql end declare section */
#line 29 "passenger.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select name , passport_id from passenger where passport_id = $1 ", 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 31 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 31 "passenger.cpp"


	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2))
	{
		cout << "Не найдено\n";
		return;
	}

	cout << endl;
	cout << "ФИО: " << n << endl;
  cout << "Номер пасспорта: " << pid << endl;
	cout << endl;
	return;
}
void update_passenger() {

	cout << "Введите ФИО пассажира:" << endl;
	string tmpname;
	cin >> tmpname;
	const char* name = tmpname.c_str();

	cout << "Введите номер паспорта:" << endl;
	int passport_id; cin >> passport_id;


	/* exec sql begin declare section */
	    
     

	
#line 57 "passenger.cpp"
 const char * n = name ;
 
#line 58 "passenger.cpp"
 int pid = passport_id ;
/* exec sql end declare section */
#line 60 "passenger.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update passenger set name = $1  where passport_id = $2 ", 
	ECPGt_char,&(n),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 61 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 61 "passenger.cpp"


	{ ECPGtrans(__LINE__, NULL, "commit");
#line 63 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 63 "passenger.cpp"

	return;
}
void delete_passenger() {
	cout << "Введите номер паспорта:" << endl;
	int passport_id; cin >> passport_id;

	/* exec sql begin declare section */
	   
	
#line 71 "passenger.cpp"
 int pid = passport_id ;
/* exec sql end declare section */
#line 72 "passenger.cpp"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from passenger where passport_id = $1 ", 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 73 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 73 "passenger.cpp"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 74 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 74 "passenger.cpp"

	return;
}
void printTable_passenger() {
	/* exec sql begin declare section */
    
   


	
#line 79 "passenger.cpp"
 char n [ 256 ] ;
 
#line 80 "passenger.cpp"
 int pid ;
/* exec sql end declare section */
#line 83 "passenger.cpp"



	ECPGset_var( 0, &( pid ), __LINE__);\
 ECPGset_var( 1, ( n ), __LINE__);\
 /* declare cursor_passenger cursor for select name , passport_id from passenger order by name */
#line 87 "passenger.cpp"


	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_passenger cursor for select name , passport_id from passenger order by name", ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 89 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 89 "passenger.cpp"


	while (true) {
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_passenger", ECPGt_EOIT, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(n),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(pid),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 92 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 92 "passenger.cpp"


		if (sqlca.sqlcode == ECPG_NOT_FOUND) {
			break;
		}

		cout << endl;
		cout << "ФИО: " << n << endl;
		cout << "Номер пасспорта: " << pid << endl;
		cout << endl;
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_passenger", ECPGt_EOIT, ECPGt_EORT);
#line 104 "passenger.cpp"

if (sqlca.sqlcode < 0) sqlprint();}
#line 104 "passenger.cpp"

	return;
}
void menu_passenger(){
	while (true) {
		cout << "Меню управления Пассажирами:" << endl;
		cout << "1. Создать запись пассажира" << endl;
		cout << "2. Найти пассажира по пасспарту" << endl;
		cout << "3. Модифицировать информацию о пассажире" << endl;
		cout << "4. Удалить запись пассажира" << endl;
		cout << "5. Показать всех пассажиров" << endl;
		cout << "0. Выйти" << endl;
		int number;
		cin >> number;
		switch (number) {
			case 1: {
				create_passenger();
				break;
			}
			case 2: {
				show_passenger();
				break;
			}
			case 3: {
				update_passenger();
				break;
			}
			case 4: {
				delete_passenger();
				break;
			}
			case 5: {
				printTable_passenger();
				break;
			}
			case 0: {
				return;
			}
		}
	}
}
