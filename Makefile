
default: test

test:	test.c example.c
	gcc test.c example.c
	./a.out	

