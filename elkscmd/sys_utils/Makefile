include ../Make.defs

PRGS=init getty login kill man mount reboot passwd umount clock \
	exitemu ps who # insmod 

MIN_PRGS=init getty login kill mount reboot umount clock exitemu ps who

all: $(PRGS)

rfs: all
	cp -p $(PRGS) $(TARGET_MNT)/bin

min_rfs: all
	cp -p $(MIN_PRGS) $(TARGET_MNT)/bin

clean:
	rm -f $(PRGS) *.o

passwd: getpass.o passwd.o


utent.o: utent.c
	$(CC) $(CFLAGS) -c utent.c

# Trim stack space of core programs.
# The -H option is the maximum size the data segment can be.
# If the code is modified, this value has to be carefully trimmed
# to fit the programs requirements. At the moment it is data + bss +
# 1024 bytes at least for even the smalled programs. Binaries which
# call malloc will need much more than this.

getty: getty.c
	$(CC) $(CFLAGS) $(LDFLAGS) getty.c -o getty -H 45C

init: init.c utent.o
	$(CC) $(CFLAGS) $(LDFLAGS) init.c utent.o -o init -H 9A4

login: getpass.o login.o utent.o
	$(CC) $(CFLAGS) $(LDFLAGS) getpass.o login.o utent.o -o login -H 2000