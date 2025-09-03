-- DROP SCHEMA public;

CREATE SCHEMA public AUTHORIZATION pg_database_owner;

-- DROP SEQUENCE public.earnings_id_seq;

CREATE SEQUENCE public.earnings_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;
-- DROP SEQUENCE public.employees_id_seq;

CREATE SEQUENCE public.employees_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;
-- DROP SEQUENCE public.game_sessions_id_seq;

CREATE SEQUENCE public.game_sessions_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;
-- DROP SEQUENCE public.games_id_seq;

CREATE SEQUENCE public.games_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;
-- DROP SEQUENCE public.roles_id_seq;

CREATE SEQUENCE public.roles_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;
-- DROP SEQUENCE public.transactions_id_seq;

CREATE SEQUENCE public.transactions_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;
-- DROP SEQUENCE public.users_id_seq;

CREATE SEQUENCE public.users_id_seq
	INCREMENT BY 1
	MINVALUE 1
	MAXVALUE 9223372036854775807
	START 1
	CACHE 1
	NO CYCLE;-- public.games definition

-- Drop table

-- DROP TABLE public.games;

CREATE TABLE public.games (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	"name" text NOT NULL,
	description text NULL,
	CONSTRAINT games_pkey PRIMARY KEY (id)
);


-- public.roles definition

-- Drop table

-- DROP TABLE public.roles;

CREATE TABLE public.roles (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	"name" text NOT NULL,
	CONSTRAINT roles_pkey PRIMARY KEY (id)
);


-- public.earnings definition

-- Drop table

-- DROP TABLE public.earnings;

CREATE TABLE public.earnings (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	game_id int8 NULL,
	amount numeric NOT NULL,
	recorded_at timestamptz DEFAULT now() NULL,
	CONSTRAINT earnings_pkey PRIMARY KEY (id),
	CONSTRAINT earnings_game_id_fkey FOREIGN KEY (game_id) REFERENCES public.games(id)
);


-- public.users definition

-- Drop table

-- DROP TABLE public.users;

CREATE TABLE public.users (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	username text NOT NULL,
	"password" text NOT NULL,
	role_id int8 NULL,
	chips int8 DEFAULT 0 NULL,
	fecha_de_nacimiento date NOT NULL,
	"name" varchar NOT NULL,
	lastname varchar NOT NULL,
	email varchar NOT NULL,
	CONSTRAINT users_pkey PRIMARY KEY (id),
	CONSTRAINT users_username_key UNIQUE (username),
	CONSTRAINT users_role_id_fkey FOREIGN KEY (role_id) REFERENCES public.roles(id)
);


-- public.employees definition

-- Drop table

-- DROP TABLE public.employees;

CREATE TABLE public.employees (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	user_id int8 NULL,
	"position" text NOT NULL,
	CONSTRAINT employees_pkey PRIMARY KEY (id),
	CONSTRAINT employees_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.users(id)
);


-- public.game_sessions definition

-- Drop table

-- DROP TABLE public.game_sessions;

CREATE TABLE public.game_sessions (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	game_id int8 NOT NULL,
	user_id int8 NOT NULL,
	start_time timestamptz DEFAULT now() NULL,
	end_time timestamptz NULL,
	money_spent int8 NOT NULL,
	CONSTRAINT game_sessions_pkey PRIMARY KEY (id),
	CONSTRAINT game_sessions_game_id_fkey FOREIGN KEY (game_id) REFERENCES public.games(id),
	CONSTRAINT game_sessions_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.users(id)
);


-- public.transactions definition

-- Drop table

-- DROP TABLE public.transactions;

CREATE TABLE public.transactions (
	id int8 GENERATED ALWAYS AS IDENTITY( INCREMENT BY 1 MINVALUE 1 MAXVALUE 9223372036854775807 START 1 CACHE 1 NO CYCLE) NOT NULL,
	user_id int8 NULL,
	amount numeric NOT NULL,
	transaction_type text NULL,
	created_at timestamptz DEFAULT now() NULL,
	CONSTRAINT transactions_pkey PRIMARY KEY (id),
	CONSTRAINT transactions_transaction_type_check CHECK ((transaction_type = ANY (ARRAY['entry'::text, 'exit'::text]))),
	CONSTRAINT transactions_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.users(id)
);
