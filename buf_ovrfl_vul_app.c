/* !!! This is a buffer overflow vulnerable app! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void vulnerable_function(void) {
    char buf[5] = {0};
    FILE *fp;

    /* Open the malicious file */
    fp = fopen("./malicious", "r");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        long length = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        fread(buf, 1, length, fp);
    }

    printf("%s\n", buf);

    //flose(fp);
}

int main(void) {
    vulnerable_function();

    return 0;
}

