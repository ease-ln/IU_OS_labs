#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	struct stat src_st;
	struct stat dest_st;

	int SRC = open("ex1.txt", O_RDWR);
	int DEST = open("ex1.memcpy.txt", O_RDWR);

	fstat(SRC, &src_st);
	fstat(DEST, &dest_st);

	char *mapping_src = mmap(NULL, src_st.st_size, PROT_READ, MAP_SHARED, SRC, 0);
	char *mapping_dest = mmap(NULL, dest_st.st_size, PROT_WRITE, MAP_SHARED, DEST, 0);

	ftruncate(DEST, strlen(mapping_src)*sizeof(char));
	memcpy(mapping_dest, mapping_src, src_st.st_size);
	close(SRC);
	close(DEST);

	return 0;
}
