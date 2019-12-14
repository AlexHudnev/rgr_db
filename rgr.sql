CREATE DOMAIN name_type char(40) NOT NULL;
CREATE DOMAIN square_type real NOT NULL;
CREATE DOMAIN year_type integer NOT NULL;
CREATE DOMAIN state_device_type char(20) NOT NULL;
CREATE DOMAIN score_type char(5) NOT NULL;
CREATE DOMAIN density_type bigint NOT NULL;

CREATE TABLE country(
	name name_type,
	state_device state_device_type,
  leader_name name_type,
  square square_type,
  population_density density_type,
	PRIMARY KEY(name)

);

CREATE TABLE state (
	name name_type,
  country_name name_type,
  leader_name name_type,
  square square_type,
  population_density density_type,
  foreign key (country_name) references country (name),
	PRIMARY KEY(name, country_name)
);

CREATE TABLE city (
	name name_type,
  country_name name_type,
  state_name name_type,
  leader_name name_type,
  foreign key (country_name, state_name) references state (country_name, name),
	PRIMARY KEY(name, country_name, state_name)
);

CREATE TABLE transport_route (
	number integer,
  start_city name_type,
  start_country_name name_type,
  start_state_name name_type,
  finish_city name_type,
  finish_country_name name_type,
  finish_state_name name_type,
  foreign key (start_city, start_country_name, start_state_name ) references city (name, country_name, state_name),
  foreign key (finish_city, finish_country_name, finish_state_name ) references city (name, country_name, state_name),

	PRIMARY KEY(number, start_city, start_country_name, start_state_name , finish_city, finish_country_name, finish_state_name )
);

CREATE TABLE passenger (
passport_id bigint,
name name_type,
PRIMARY KEY(passport_id)
);

CREATE TABLE trip (
  date date,
	transport_type name_type,
  passenger_passport_id bigint,
  transport_route_number integer,
  start_city name_type,
  start_country_name name_type,
  start_state_name name_type,
  finish_city name_type,
  finish_country_name name_type,
  finish_state_name name_type,
  foreign key (transport_route_number, start_city, start_country_name, start_state_name, finish_city, finish_country_name, finish_state_name) references transport_route (number, start_city, start_country_name, start_state_name, finish_city, finish_country_name, finish_state_name),
  foreign key (passenger_passport_id) references passenger (passport_id),
  PRIMARY KEY(passenger_passport_id, transport_route_number, date )
);
