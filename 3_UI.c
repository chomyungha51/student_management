#include "header.h"

void main() {

    //total courses initialize


    r = (TOTAL*)malloc(sizeof(TOTAL));
    create_nilnode(r);

    valid_grade[0] = 'A';
    valid_grade[1] = 'B';
    valid_grade[2] = 'C';
    valid_grade[3] = 'D';
    valid_grade[4] = 'F';

	srand(time(NULL));
    int student_ids[100];
    int dup;
    int temp;
    
    for (int i = 0; i < 10; i++) {
        dup = 0;
        while (1) {
            temp = rand() % (2018999999 + 1 - 201800000) + 201800000;
            dup = 0;
            for (int j = 0; j < i; j++) {
                if (student_ids[j] == temp) {
                    dup = 1;
                    break;
                }
            }
            if (dup == 0) {
                student_ids[i] = temp;
                insert_node(r, temp, NULL);
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        delete_node(r, student_ids[i]);
    }
    print_rb_info(r, r->r);
    print_student_info(r, search_student(r, r->r, student_ids[5]));
    printf("%d\n", get_total_students(r, r->r));
}