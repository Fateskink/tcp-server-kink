all: tcp srv

tcp: tcp.c
	gcc tcp.c -o tcp

srv: srv.c
	gcc srv.c -o srv

clean:
	rm -f tcp srv
