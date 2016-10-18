###inode_num

USAGE:
```
root@devit:~/inode_num# ls|xargs ./inode_num
inode_num: 3562047
inode_num.c: 3562046
Makefile: 3562044
root@devit:~/inode_num# ./inode_num /bin/netstat
/bin/netstat: 3670023
```

ERRORS:
```
root@devit:~/inode_num# sudo -u testu /home/testu/inode_num /root/test
/root/test: Permission denied
root@devit:~/inode_num# ./inode_num doesnt_exist
doesnt_exist: No such file or directory
```
