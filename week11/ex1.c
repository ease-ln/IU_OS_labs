#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	struct stat st;
	char *string = "This is a nice day";
	int FILE = open("ex1.txt", O_RDWR);
	fstat(FILE, &st);
	char *mapping = mmap(NULL, st.st_size, PROT_WRITE, MAP_SHARED, FILE, 0);
    ftruncate(FILE, strlen(string)*sizeof(char));
	strcpy(mapping, string);
	close(FILE);
	return 0;
}
