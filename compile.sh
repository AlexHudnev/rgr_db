ecpg state.cpp
ecpg country.cpp
ecpg city.cpp
ecpg passenger.cpp
ecpg trip.cpp
ecpg transport_route.cpp
ecpg rgr.pgc
g++ -I /usr/include/postgresql -I/usr/local/pgsql/lib -lecpg -lpq  -c rgr.c
g++ -o rgr rgr.o -I /usr/include/postgresql -I/usr/local/pgsql/lib -lecpg -lpq

