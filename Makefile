run: comp
	./test | cat -e
# -Wall -Wextra -Werror 
comp:
	cc *.c -o test
