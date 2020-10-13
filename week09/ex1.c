#include <stdlib.h>
#include <stdio.h>

const int frame_size = 10;
int find_min();

 struct frame {
    int age;
    int number;
    int reference;
};

struct frame *frames;

int main() {

	int hit = 0;
	int miss = 0;

    FILE *file = fopen("input.txt", "r");

	frames = malloc(3*sizeof(int));

    for (int i = 0; i < frame_size; i++) {
		frames[i].age = 0;
		frames[i].number = -1;
		frames[i].reference = 0;
	}

    int frame_input_num = 0;

	while (fscanf (file, "%d", &frame_input_num) != EOF) {
        int temp = hit;

        for(int i = 0; i < frame_size; i++) {
            frames[i].age = frames[i].age >> 1;

            if(frames[i].number == frame_input_num && frames[i].reference == 1) {
                hit++;
                frames[i].age += 128; //1000 000
            }
        }

        if(temp == hit){
            int imin = 0;
            int j = 0;

            for(j = 0; j < frame_size; j++) {
                if(frames[j].reference == 0){
                    imin = j;
                    j = frame_size + 1;
                }
            }


            if(frame_size == j){
                imin = find_min();
            }
            frames[imin].reference = 1;
            frames[imin].number = frame_input_num;
            frames[imin].age = 128;
            miss++;

            }
        }


    printf("%d/%d = %f", hit, miss, (float)hit/(float)miss);
    fclose(file);
    free(frames);
	}

int find_min() {
    int min = 256;
    int j = 0;
    for(int i = 0; i < frame_size; i++) {
       if(min > frames[i].age) {
            min = frames[i].age;
            j = i;
       }
    return j;
}}
