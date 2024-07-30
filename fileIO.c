#include <stdio.h>
#include <stdlib.h>

int main(){

    int id, year, sum1;
    string_t name, _name;

    /* Open the file */
    FILE*  nameFile  = fopen("babynames.csv", "r");

    printf("Pick a name\n");
    scanf("%s", &_name);

    // loop through the data untill the EOF
    while(!feof(nameFile)){
        fscanf("%d,%d,%d,%s", &id, &count, &year, &name);
        if(name == _name){
            sum1 = sum1 + count;
        }
    }
    
    printf("There are %d people with the name %s\n", sum1, _name);
    return 0;
}