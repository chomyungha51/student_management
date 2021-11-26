#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1 
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define MAXSTUDENT 500

typedef struct node
{
    struct node* p;
    struct node* left;
    struct node* right;

    int clr;
    int key; //student_id
    int gpa;
    int remain_credit;
    COURSE* enrolled;
} NODE;

typedef struct rbtree
{
    NODE* r;
    NODE* nil;
} ROOT;

typedef struct course
{
    char* semester;
    char* course_id;
    int credit;
    int point;
    char grade;
    struct course* next;

}COURSE;

typedef struct enroll
{
    char* course_id;
    char grade;
}ENROLL;

ROOT* r;

void create_nilnode(ROOT* r);
void insert_node(ROOT* r, int key);
void insert_fixup(ROOT* r, NODE* x);
void tree_transplant(ROOT* r, NODE* t, NODE* c);
void left_rotate(ROOT* r, NODE* x);
void right_rotate(ROOT* r, NODE* y);
void delete_node(ROOT* r, int key);
void delete_course(ROOT* r, int key, char* course_id);
void delete_fixup(ROOT* r, NODE* x);

void print_tree(ROOT* r, NODE* n);
int getNodes(ROOT* r, NODE* n);
void getRootKey(ROOT* r);
void getLevesKey(ROOT* r, NODE* n);
int getHeight(ROOT* r, NODE* n);

void print_student_info(int student_id);



