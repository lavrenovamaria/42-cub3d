#include <stdio.h>
#include <stdlib.h>

#define MWIDTH  100
#define MHEIGHT 100

int main(void){

    FILE* f;
    int height, width, ii, jj;
    float array[MHEIGHT][MWIDTH];

    if((f = fopen("file.txt", "r")) == NULL)
        exit(1);

    if(fscanf(f, "%d%d", &height, &width) != 2)
        exit(1);
    if (height < 1 || height > MHEIGHT || width < 1 || width > MWIDTH)
        exit(1);

    for(jj=0; jj<height; jj++)
        for(ii=0; ii<width; ii++)
            if(fscanf(f, "%f", &array[jj][ii]) != 1)
                exit(1);
    fclose(f);

    for(jj=0; jj<height; jj++){
        for(ii=0; ii<width; ii++)
            printf ("%10.1f", array[jj][ii]);
        printf("\n");
    }
    return 0;
}
