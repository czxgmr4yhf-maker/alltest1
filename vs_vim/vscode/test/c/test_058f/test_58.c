#include <stdio.h>
#include <string.h>

typedef struct {
    char id[32];
    char name[32];
    int grade;
} Student;

int main(){
    char line[100];
    int sum = 0;
    int num = 0;


    FILE *fp = fopen("score.txt", "w+");
    while(fgets(line, sizeof(line), stdin)) {
        if(!strcmp(line, "\n")) break;

        Student student;
        sscanf(line, "%s %s %d",
            student.id,
            student.name,
            &student.grade);
        fprintf(fp, "%s %s %d\n", student.id, student.name, student.grade);

        sum += student.grade;
        num++;
    }

    printf("\n学号,姓名,成绩分别如下:\n");
    rewind(fp);
    char read[100];
    while(fgets(read, sizeof(read), fp)) {
        printf("%s", read);
    }
    double avgGrade = 1.0 * sum / num;
    printf("\n平均成绩为:%.2f\n", avgGrade);

    fclose(fp);
    printf("文件修改完毕\n");
}