#include <stdio.h>
#include <string.h>

typedef struct {
    char id[32];
    char name[32];
    char sex;
    double chinese;
    double math;
    double english;
    double avg; 
} Student;
//-----------主菜单--------//
int menue(){
    printf("================ 学生成绩管理系统 ================\n");
    printf("1. 添加学生信息\n");
    printf("2. 查询学生信息\n");
    printf("3. 修改学生信息\n");
    printf("4. 删除学生信息\n");
    printf("5. 显示所有学生信息\n");
    printf("6. 保存到文件(students.txt)\n");
    printf("7. 从文件读取(students.txt)\n");
    printf("0. 退出\n");
    printf("=================================================\n");
    printf("请输入菜单选项：");
    int pointer;
    scanf("%d", &pointer);
    return pointer;
}
//-----------从一行字符串中读取一个个体--------//
Student person(const char *line) {
    Student singlePerson;
    sscanf(line, "%31[^,],%31[^,],%c,%lf,%lf,%lf,%lf", 
        singlePerson.id, 
        singlePerson.name, 
        &singlePerson.sex,  
        &singlePerson.chinese, 
        &singlePerson.math, 
        &singlePerson.english,
        &singlePerson.avg);
    
    return singlePerson;
}
//-----------创建一个个体--------//
Student creatPerson(){
    Student singlePerson;
    printf("学号：");
    scanf(" %31s", singlePerson.id);
    printf("姓名：");
    scanf(" %31s", singlePerson.name);
    printf("性别(M/F): ");
    scanf(" %c", &singlePerson.sex);
    printf("语文成绩：");
    scanf(" %lf", &singlePerson.chinese);
    printf("数学成绩：");
    scanf(" %lf", &singlePerson.math);
    printf("英语成绩：");
    scanf(" %lf", &singlePerson.english);
    singlePerson.avg = 1.0 * (singlePerson.chinese + singlePerson.math + singlePerson.english) / 3;

    return singlePerson;
}
//-----------打印某个个体的所有信息--------//
void personPrint(Student singlePerson) {
     printf("---------------------------------------------------------------\n");
    printf("ID\t\tName\tSEX\tCHINESE\tMATH\tENGLISH\tAVG\n");
    printf("---------------------------------------------------------------\n");
    printf("%s\t%s\t%c\t%.2f\t%.2f\t%.2f\t%.2f\n", 
        singlePerson.id, 
        singlePerson.name, 
        singlePerson.sex, 
        singlePerson.chinese, 
        singlePerson.math,
        singlePerson.english, 
        singlePerson.avg);
}
//-----------向文件中写入个体信息--------//
void writeFile(FILE *fp, Student singlePerson) {
    fprintf(fp, "%s,%s,%c,%.2f,%.2f,%.2f,%.2f\n",
        singlePerson.id,
        singlePerson.name,
        singlePerson.sex,
        singlePerson.chinese,
        singlePerson.math,
        singlePerson.english,
        singlePerson.avg);
}
//-----------查看所有学生信息--------//
void show() {
    FILE *fp = fopen("students.txt", "r");
    if(!fp) return;
    
    char line[1000];
    while(fgets(line, sizeof(line), fp)) {
        Student singlePerson = person(line);                 
        personPrint(singlePerson);
    }

    fclose(fp);
}
//-----------添加学生信息--------//
void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    if(!fp) return;

    Student singlePerson = creatPerson();
    writeFile(fp, singlePerson);

    personPrint(singlePerson);

    fclose(fp);
}
//-----------修改学生信息--------//
void upgradeStudent() {
    FILE *fpr = fopen("students.txt", "r");
    if (!fpr) return;

    FILE *fpw = fopen("new.txt", "w");
    if (!fpw) {
        fclose(fpr);
        return;
    }

    char line[100];
    printf("请输入您想要修改的学生(学号): ");
    char ssID[32];
    scanf("%31s", ssID);

    while (fgets(line, sizeof(line), fpr)) {
        Student sinPerson = person(line);
        if (strcmp(sinPerson.id, ssID) != 0) {
            writeFile(fpw, sinPerson);
        } else {
            printf("\n");
            personPrint(sinPerson);
            printf("现在开始修改学号为%s的学员信息:\n\n", sinPerson.id);

            sinPerson = creatPerson();

            writeFile(fpw, sinPerson);
            personPrint(sinPerson);
        } 
    }

    fclose(fpr);
    fclose(fpw);
    remove("students.txt");
    rename("new.txt", "students.txt");
}

int main(){
    while(1) {
        int pointer = menue();
        //printf("pointer = %d\n", pointer);

        switch(pointer) {
            case 0:
                printf("退出成功,祝您生活愉快\n\n\n");
                return 0;

            case 1:
                addStudent();
                printf("写入完成\n\n\n");
                break;

            case 3:
                upgradeStudent();
                printf("恭喜!!!信息修改成功\n\n\n");
                break;

            case 5:
                show();
                break;

            default:
                printf("这只是个测试，您需要选有效的数字\n\n\n");
                break;
        }

    }
}