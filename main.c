#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "header.h"

void main() {
	printf("Start program\n");

    // 처음에 최소 100명 학생들로 초기화
    // 평균적으로 70학점 완료했음

    ROOT* r = (ROOT*)malloc(sizeof(ROOT));
    int student_info[MAXSTUDENT];

    srand(time(NULL));
    
    for (int i = 0; i < 100; i++) {
        int dup = 0;
        while (1) {
            int temp = rand() % (201699999 + 1 - 20140000) + 20140000;
            dup = 0;
            for (int j = 0; j < i; i++) {
                if (student_info[j] == temp) {
                    dup = 1;
                    break;
                }  
            }
            if (dup == 0) {
                student_info[i] = temp;
                break;
            }
        }
    }

    //과목명 생성
    COURSE courses[24];
    char* depart[6] = { "SWE", "BIZ", "CHS","ART","CHY", "KOR" };

    //3학점 20과목
    for (int i = 0; i < 20; i++) {
        int dup = 0;
        char tar[3] = depart[rand() % 6];
        char* cur = (char*)malloc(sizeof(char) * 7);
        strcpy(cur, tar);
        while (1) {
            int temp = rand() % (3025 + 1 - 2005) + 2005;
            char space[4];
            strcat(cur, itoa(temp, space, 10));
            dup = 0;
            for (int j = 0; j < i; i++) {
                if (strcmp(courses[j].course_id, cur) == 0) {
                    dup = 1;
                    break;
                }
            }
            if (dup == 0) {
                courses[i].course_id = cur;
                courses[i].semester;
                courses[i].course_id;
                courses[i].credit;
                break;
            }
        }
    }
    //2학점 2과목
    for (int i = 0; i < 20; i++) {
        int dup = 0;
        char tar[3] = depart[rand() % 6];
        char* cur = (char*)malloc(sizeof(char) * 7);
        strcpy(cur, tar);
        while (1) {
            int temp = rand() % (3025 + 1 - 2005) + 2005;
            char space[4];
            strcat(cur, itoa(temp, space, 10));
            dup = 0;
            for (int j = 0; j < i; i++) {
                if (strcmp(course_ids[j], cur) == 0) {
                    dup = 1;
                    break;
                }
            }
            if (dup == 0) {
                course_ids[i] = cur;
                break;
            }
        }
    }
    //1학점 2과목
    for (int i = 0; i < 20; i++) {
        int dup = 0;
        char tar[3] = depart[rand() % 6];
        char* cur = (char*)malloc(sizeof(char) * 7);
        strcpy(cur, tar);
        while (1) {
            int temp = rand() % (3025 + 1 - 2005) + 2005;
            char space[4];
            strcat(cur, itoa(temp, space, 10));
            dup = 0;
            for (int j = 0; j < i; i++) {
                if (strcmp(course_ids[j], cur) == 0) {
                    dup = 1;
                    break;
                }
            }
            if (dup == 0) {
                course_ids[i] = cur;
                break;
            }
        }
    }

    char grades[5] = {'A','B', 'C', 'D', 'F'};

    create_nilnode(r);

    for (int i = 0; i < 100; i++) {

        //3학점 20과목

        int index = rand() % 50;
        char course[7] = course_ids[index];

        index = rand() % 5;
        char grade = grades[index];

        int temp = rand() % (2021 + 1 - 2018) + 2018;
        char space[6];
        char* half[2] = { "-1", "-2" };
        index = rand() % 1;
        strcat(itoa(temp, space, 10), half[index]);

        insert_node(r, student_info[i], course, grade, 3, space);
        
        for (int j = 0; j < 19; j++) {
            int index = rand() % 50;
            char course[7] = course_ids[index];

            index = rand() % 5;
            char grade = grades[index];

            int temp = rand() % (2021 + 1 - 2018) + 2018;
            char space[6];
            char* half[2] = { "-1", "-2" };
            index = rand() % 1;
            strcat(itoa(temp, space, 10), half[index]);

            NODE* current = search_node(r, r->r, student_info[i]);
            update_info(r, current, student_info[i], grade, 3, space);

        }//2학점 10과목
        for (int j = 0; j < 10; j++) {
            int index = rand() % 50;
            char course[7] = course_ids[index];

            index = rand() % 5;
            char grade = grades[index];

            int temp = rand() % (2021 + 1 - 2018) + 2018;
            char space[6];
            char* half[2] = { "-1", "-2" };
            index = rand() % 1;
            strcat(itoa(temp, space, 10), half[index]);

            NODE* current = search_node(r, r->r, student_info[i]);
            update_info(r, current, student_info[i], grade, 2, space);
        }

        
       
    }
    
    printf("\nTotal Nodes: %d\n", getNodes(r, r->r));
    getRootKey(r);
    getLevesKey(r, r->r);
    printf("\nHeight: %d\n", getHeight(r, r->r));

    return ;
}
