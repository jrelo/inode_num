CC      = gcc
CFLAGS  = -g -march=native -O2 -pipe -Werror
RM      = rm -f


default: all

all: inode_num

inode_num: inode_num.c
	$(CC) $(CFLAGS) -o inode_num inode_num.c

clean veryclean:
	$(RM) inode_num
