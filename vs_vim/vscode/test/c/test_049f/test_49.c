#include <stdio.h>

double scores(int m, int grade[m + 1]);
int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int students[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &students[i][j]);
        }
    }

    double grades[n + 1];
    for (int i = 1; i <= n; i++) {
        grades[i] = scores(m, students[i]);
    }
    
    grades[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (grades[0] < grades[i]) grades[0] = grades[i];
    }

    printf("%.2lf\n", grades[0]);
}
double scores(int m, int grade[m + 1]) {
    int sum = 0;
    int min = grade[1];
    int max = grade[1];
    for (int i = 1; i <= m; i++) {
        sum += grade[i];
        if (min > grade[i]) min = grade[i];
        if (max < grade[i]) max = grade[i];
    }
    
    double score = 1.0 * (sum - min - max) / (m - 2);
    return score;
}