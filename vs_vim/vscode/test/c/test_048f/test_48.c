// ===== file: main.c =====
// 学生成绩管理系统（命令行交互）
// 功能：添加/查询(学号精确、姓名模糊)/修改/删除/显示/文件保存读取
// 数据：student.txt（CSV 逗号分隔）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define ID_LEN      32
#define NAME_LEN    32
#define LINE_LEN    256
#define FILE_NAME   "student.txt"

typedef struct {
    char  id[ID_LEN];      // 学号（字符串）
    char  name[NAME_LEN];  // 姓名（字符串）
    char  gender;          // 性别：M/F
    float chinese;         // 语文
    float math;            // 数学
    float english;         // 英语
    float avg;             // 平均分（自动计算）
} Student;

/* ---------- 工具函数 ---------- */

static void trim_newline(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

static void read_line(const char *prompt, char *buf, size_t size) {
    if (!buf || size == 0) return;
    if (prompt) printf("%s", prompt);

    if (!fgets(buf, (int)size, stdin)) {
        // EOF 或错误：给个空串，避免未初始化
        buf[0] = '\0';
        return;
    }
    trim_newline(buf);
}

static int is_blank_str(const char *s) {
    if (!s) return 1;
    while (*s) {
        if (!isspace((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}

static int read_required_string(const char *prompt, char *out, size_t size) {
    char tmp[LINE_LEN];
    read_line(prompt, tmp, sizeof(tmp));
    if (is_blank_str(tmp)) return 0;
    // 截断拷贝
    snprintf(out, size, "%s", tmp);
    return 1;
}

static int parse_float(const char *s, float *out) {
    if (!s || !out) return 0;
    errno = 0;
    char *end = NULL;
    float v = strtof(s, &end);
    if (errno != 0) return 0;
    if (end == s) return 0;               // 没有解析出任何数字
    while (*end) {
        if (!isspace((unsigned char)*end)) return 0; // 有非空白尾巴
        end++;
    }
    *out = v;
    return 1;
}

static int read_float_in_range(const char *prompt, float *out, float minv, float maxv) {
    char tmp[LINE_LEN];
    read_line(prompt, tmp, sizeof(tmp));
    float v;
    if (!parse_float(tmp, &v)) return 0;
    if (v < minv || v > maxv) return 0;
    *out = v;
    return 1;
}

static int read_gender_required(const char *prompt, char *out_gender) {
    char tmp[LINE_LEN];
    read_line(prompt, tmp, sizeof(tmp));
    if (strlen(tmp) != 1) return 0;
    char g = (char)toupper((unsigned char)tmp[0]);
    if (g != 'M' && g != 'F') return 0;
    *out_gender = g;
    return 1;
}

static void compute_avg(Student *s) {
    if (!s) return;
    s->avg = (s->chinese + s->math + s->english) / 3.0f;
}

static int find_student_by_id(const Student *arr, size_t n, const char *id) {
    if (!arr || !id) return -1;
    for (size_t i = 0; i < n; i++) {
        if (strcmp(arr[i].id, id) == 0) return (int)i;
    }
    return -1;
}

static int ensure_capacity(Student **arr, size_t *cap, size_t need) {
    if (!arr || !cap) return 0;
    if (*cap >= need) return 1;

    size_t new_cap = (*cap == 0) ? 16 : (*cap * 2);
    while (new_cap < need) new_cap *= 2;

    Student *p = (Student *)realloc(*arr, new_cap * sizeof(Student));
    if (!p) return 0;
    *arr = p;
    *cap = new_cap;
    return 1;
}

/* ---------- 打印 ---------- */

static void print_header(void) {
    printf("--------------------------------------------------------------------------------\n");
    printf("%-18s %-12s %-6s %8s %8s %8s %8s\n",
           "ID(学号)", "Name(姓名)", "Sex", "Chinese", "Math", "English", "Avg");
    printf("--------------------------------------------------------------------------------\n");
}

static void print_one(const Student *s) {
    printf("%-18s %-12s %-6c %8.2f %8.2f %8.2f %8.2f\n",
           s->id, s->name, s->gender, s->chinese, s->math, s->english, s->avg);
}

/* ---------- 文件读写 ---------- */

static int save_to_file(const Student *arr, size_t n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return 0;

    for (size_t i = 0; i < n; i++) {
        // CSV：id,name,gender,chinese,math,english,avg
        fprintf(fp, "%s,%s,%c,%.2f,%.2f,%.2f,%.2f\n",
                arr[i].id, arr[i].name, arr[i].gender,
                arr[i].chinese, arr[i].math, arr[i].english, arr[i].avg);
    }
    fclose(fp);
    return 1;
}

static int load_from_file(Student **arr, size_t *n, size_t *cap, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0; // 文件不存在也算“加载失败”，但主流程会提示“无文件则空表”
    char line[LINE_LEN];

    size_t count = 0;
    while (fgets(line, sizeof(line), fp)) {
        trim_newline(line);
        if (is_blank_str(line)) continue;

        // 解析 CSV
        // 允许 6 或 7 列（有些人可能没存 avg）
        char *tokens[7] = {0};
        int t = 0;

        char *p = line;
        while (t < 7) {
            tokens[t] = (t == 0) ? strtok(p, ",") : strtok(NULL, ",");
            if (!tokens[t]) break;
            t++;
        }
        if (t < 6) continue; // 至少要有 id,name,gender,3门成绩

        Student s;
        memset(&s, 0, sizeof(s));

        snprintf(s.id, ID_LEN, "%s", tokens[0]);
        snprintf(s.name, NAME_LEN, "%s", tokens[1]);
        s.gender = (char)toupper((unsigned char)tokens[2][0]);

        float c, m, e;
        if (!parse_float(tokens[3], &c)) continue;
        if (!parse_float(tokens[4], &m)) continue;
        if (!parse_float(tokens[5], &e)) continue;

        // 基本校验
        if (is_blank_str(s.id) || is_blank_str(s.name)) continue;
        if (s.gender != 'M' && s.gender != 'F') continue;
        if (c < 0 || c > 100 || m < 0 || m > 100 || e < 0 || e > 100) continue;

        s.chinese = c; s.math = m; s.english = e;
        compute_avg(&s);

        // 学号唯一：若重复则跳过后者
        if (find_student_by_id(*arr, count, s.id) != -1) continue;

        if (!ensure_capacity(arr, cap, count + 1)) {
            fclose(fp);
            return 0;
        }
        (*arr)[count++] = s;
    }

    fclose(fp);
    *n = count;
    return 1;
}

/* ---------- 业务功能 ---------- */

static void add_student(Student **arr, size_t *n, size_t *cap) {
    Student s;
    memset(&s, 0, sizeof(s));

    // 学号（唯一）
    while (1) {
        if (!read_required_string("输入学号(字符串，不能为空)：", s.id, ID_LEN)) {
            printf("学号不能为空。\n");
            continue;
        }
        if (find_student_by_id(*arr, *n, s.id) != -1) {
            printf("学号已存在，不能重复。\n");
            continue;
        }
        break;
    }

    // 姓名
    while (!read_required_string("输入姓名(字符串，不能为空)：", s.name, NAME_LEN)) {
        printf("姓名不能为空。\n");
    }

    // 性别
    while (!read_gender_required("输入性别(M/F)：", &s.gender)) {
        printf("性别不合法，只能输入 M 或 F。\n");
    }

    // 成绩
    while (!read_float_in_range("输入语文成绩(0-100)：", &s.chinese, 0.0f, 100.0f)) {
        printf("成绩不合法，必须是 0~100 的数字。\n");
    }
    while (!read_float_in_range("输入数学成绩(0-100)：", &s.math, 0.0f, 100.0f)) {
        printf("成绩不合法，必须是 0~100 的数字。\n");
    }
    while (!read_float_in_range("输入英语成绩(0-100)：", &s.english, 0.0f, 100.0f)) {
        printf("成绩不合法，必须是 0~100 的数字。\n");
    }

    compute_avg(&s);

    if (!ensure_capacity(arr, cap, *n + 1)) {
        printf("内存不足，添加失败。\n");
        return;
    }
    (*arr)[(*n)++] = s;

    printf("添加成功！平均分：%.2f\n", s.avg);
}

static void query_by_id(const Student *arr, size_t n) {
    char id[ID_LEN];
    if (!read_required_string("输入学号进行精确查询：", id, ID_LEN)) {
        printf("学号不能为空。\n");
        return;
    }
    int idx = find_student_by_id(arr, n, id);
    if (idx == -1) {
        printf("未找到学号为 %s 的学生。\n", id);
        return;
    }
    print_header();
    print_one(&arr[idx]);
}

static void query_by_name_fuzzy(const Student *arr, size_t n) {
    char key[NAME_LEN];
    if (!read_required_string("输入姓名关键字进行模糊查询(如“张”)：", key, NAME_LEN)) {
        printf("关键字不能为空。\n");
        return;
    }

    int found = 0;
    print_header();
    for (size_t i = 0; i < n; i++) {
        if (strstr(arr[i].name, key) != NULL) {
            print_one(&arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("(无匹配记录)\n");
    }
}

static void query_student(const Student *arr, size_t n) {
    if (n == 0) {
        printf("当前无学生数据。\n");
        return;
    }
    printf("1) 按学号精确查询\n");
    printf("2) 按姓名模糊查询\n");
    char tmp[LINE_LEN];
    read_line("请选择：", tmp, sizeof(tmp));
    if (strcmp(tmp, "1") == 0) query_by_id(arr, n);
    else if (strcmp(tmp, "2") == 0) query_by_name_fuzzy(arr, n);
    else printf("无效选择。\n");
}

// 修改：支持“回车保留原值”
static int read_optional_string(const char *prompt, char *out, size_t out_size) {
    char tmp[LINE_LEN];
    read_line(prompt, tmp, sizeof(tmp));
    if (is_blank_str(tmp)) return 0; // 表示不修改
    snprintf(out, out_size, "%s", tmp);
    return 1;
}

static int read_optional_gender(const char *prompt, char *out_gender) {
    char tmp[LINE_LEN];
    read_line(prompt, tmp, sizeof(tmp));
    if (is_blank_str(tmp)) return 0; // 不修改
    if (strlen(tmp) != 1) return -1;
    char g = (char)toupper((unsigned char)tmp[0]);
    if (g != 'M' && g != 'F') return -1;
    *out_gender = g;
    return 1;
}

static int read_optional_score(const char *prompt, float *out_score) {
    char tmp[LINE_LEN];
    read_line(prompt, tmp, sizeof(tmp));
    if (is_blank_str(tmp)) return 0; // 不修改
    float v;
    if (!parse_float(tmp, &v)) return -1;
    if (v < 0.0f || v > 100.0f) return -1;
    *out_score = v;
    return 1;
}

static void modify_student(Student *arr, size_t n) {
    if (n == 0) {
        printf("当前无学生数据。\n");
        return;
    }

    char id[ID_LEN];
    if (!read_required_string("输入学号定位要修改的学生：", id, ID_LEN)) {
        printf("学号不能为空。\n");
        return;
    }
    int idx = find_student_by_id(arr, n, id);
    if (idx == -1) {
        printf("未找到学号为 %s 的学生。\n", id);
        return;
    }

    Student *s = &arr[idx];
    printf("已找到记录：\n");
    print_header();
    print_one(s);

    printf("\n开始修改（直接回车表示保留原值）：\n");

    // name
    (void)read_optional_string("新姓名(回车不改)：", s->name, NAME_LEN);

    // gender
    while (1) {
        int r = read_optional_gender("新性别(M/F，回车不改)：", &s->gender);
        if (r == 0) break;        // 不改
        if (r == 1) break;        // 改成功
        printf("性别不合法，只能输入 M/F 或回车。\n");
    }

    int score_changed = 0;

    // chinese
    while (1) {
        int r = read_optional_score("新语文(0-100，回车不改)：", &s->chinese);
        if (r == 0) break;
        if (r == 1) { score_changed = 1; break; }
        printf("成绩不合法，只能输入 0~100 或回车。\n");
    }

    // math
    while (1) {
        int r = read_optional_score("新数学(0-100，回车不改)：", &s->math);
        if (r == 0) break;
        if (r == 1) { score_changed = 1; break; }
        printf("成绩不合法，只能输入 0~100 或回车。\n");
    }

    // english
    while (1) {
        int r = read_optional_score("新英语(0-100，回车不改)：", &s->english);
        if (r == 0) break;
        if (r == 1) { score_changed = 1; break; }
        printf("成绩不合法，只能输入 0~100 或回车。\n");
    }

    if (score_changed) compute_avg(s);

    printf("修改完成。\n");
    print_header();
    print_one(s);
}

static void delete_student(Student *arr, size_t *n) {
    if (*n == 0) {
        printf("当前无学生数据。\n");
        return;
    }

    char id[ID_LEN];
    if (!read_required_string("输入学号定位要删除的学生：", id, ID_LEN)) {
        printf("学号不能为空。\n");
        return;
    }
    int idx = find_student_by_id(arr, *n, id);
    if (idx == -1) {
        printf("未找到学号为 %s 的学生。\n", id);
        return;
    }

    printf("将删除记录：\n");
    print_header();
    print_one(&arr[idx]);

    char confirm[LINE_LEN];
    read_line("确认删除？(y/N)：", confirm, sizeof(confirm));
    if (confirm[0] != 'y' && confirm[0] != 'Y') {
        printf("已取消删除。\n");
        return;
    }

    // 左移覆盖
    for (size_t i = (size_t)idx; i + 1 < *n; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;

    printf("删除成功。\n");
}

static void list_students(const Student *arr, size_t n) {
    if (n == 0) {
        printf("当前无学生数据。\n");
        return;
    }
    print_header();
    for (size_t i = 0; i < n; i++) {
        print_one(&arr[i]);
    }
}

/* ---------- 菜单 ---------- */

static void print_menu(void) {
    printf("\n================ 学生成绩管理系统 ================\n");
    printf("1. 添加学生信息\n");
    printf("2. 查询学生信息\n");
    printf("3. 修改学生信息\n");
    printf("4. 删除学生信息\n");
    printf("5. 显示所有学生信息\n");
    printf("6. 保存到文件(student.txt)\n");
    printf("7. 从文件读取(student.txt)\n");
    printf("0. 退出\n");
    printf("=================================================\n");
}

static int read_choice(void) {
    char tmp[LINE_LEN];
    read_line("请输入菜单选项：", tmp, sizeof(tmp));
    if (is_blank_str(tmp)) return -1;

    errno = 0;
    char *end = NULL;
    long v = strtol(tmp, &end, 10);
    if (errno != 0 || end == tmp) return -1;
    while (*end) {
        if (!isspace((unsigned char)*end)) return -1;
        end++;
    }
    return (int)v;
}

int main(void) {
    Student *students = NULL;
    size_t n = 0, cap = 0;

    // 启动时尝试加载
    if (load_from_file(&students, &n, &cap, FILE_NAME)) {
        printf("已从 %s 加载 %zu 条记录。\n", FILE_NAME, n);
    } else {
        printf("未找到 %s 或加载失败，当前从空数据开始。\n", FILE_NAME);
    }

    while (1) {
        print_menu();
        int choice = read_choice();
        switch (choice) {
            case 1:
                add_student(&students, &n, &cap);
                break;
            case 2:
                query_student(students, n);
                break;
            case 3:
                modify_student(students, n);
                break;
            case 4:
                delete_student(students, &n);
                break;
            case 5:
                list_students(students, n);
                break;
            case 6: {
                if (save_to_file(students, n, FILE_NAME)) {
                    printf("保存成功：%s（%zu 条记录）\n", FILE_NAME, n);
                } else {
                    printf("保存失败：无法写入 %s\n", FILE_NAME);
                }
                break;
            }
            case 7: {
                char confirm[LINE_LEN];
                read_line("读取会覆盖当前内存数据，确认读取？(y/N)：", confirm, sizeof(confirm));
                if (confirm[0] != 'y' && confirm[0] != 'Y') {
                    printf("已取消读取。\n");
                    break;
                }
                // 清空并重新加载
                n = 0;
                if (load_from_file(&students, &n, &cap, FILE_NAME)) {
                    printf("读取成功：%s（%zu 条记录）\n", FILE_NAME, n);
                } else {
                    printf("读取失败：无法读取 %s\n", FILE_NAME);
                }
                break;
            }
            case 0: {
                char confirm[LINE_LEN];
                read_line("退出前是否保存到文件？(y/N)：", confirm, sizeof(confirm));
                if (confirm[0] == 'y' || confirm[0] == 'Y') {
                    if (save_to_file(students, n, FILE_NAME)) {
                        printf("已保存。\n");
                    } else {
                        printf("保存失败。\n");
                    }
                }
                free(students);
                printf("已退出。\n");
                return 0;
            }
            default:
                printf("无效选项，请重新输入。\n");
                break;
        }
    }
}
