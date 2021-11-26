#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void create_nilnode(ROOT* r)
{
    r->nil = (NODE*)malloc(sizeof(NODE));
    (r->nil)->clr = BLACK;
    r->r = r->nil;
}

void left_rotate(ROOT* r, NODE* x)
{
    NODE* temp;

    temp = x->right;
    // turn temp's left subtree into x's right subtree
    x->right = temp->left;

    if (temp->left != r->nil)
    {
        (temp->left)->p = x;
    }

    temp->p = x->p; // link x's parent to temp

    if (x->p == r->nil)
    {
        r->r = temp;
    }
    else if (x == (x->p)->left)
    {
        (x->p)->left = temp;
    }
    else
    {
        (x->p)->right = temp;
    }

    temp->left = x; // put x on temp's left
    x->p = temp;
}

void right_rotate(ROOT* r, NODE* y)
{
    NODE* temp;

    temp = y->left;
    // turn temp's right subtree into y's left subtree
    y->left = temp->right;

    if (temp->right != r->nil)
    {
        (temp->right)->p = y;
    }

    temp->p = y->p; // link y's parent to temp

    if (y->p == r->nil)
    {
        r->r = temp;
    }
    else if (y == (y->p)->left)
    {
        (y->p)->left = temp;
    }
    else
    {
        (y->p)->right = temp;
    }

    temp->right = y; // put y on temp's right
    y->p = temp;
}

void insert_node(ROOT* r, int key, char* course_id, char grade, int credit_hour, char* semester)
{
    NODE* n = (NODE*)malloc(sizeof(NODE));
    NODE* temp = r->r;
    NODE* p = r->nil;

    n->left = r->nil;
    n->right = r->nil;
    n->clr = RED;

    n->key = key;
    n->enrolled = addCOURSE(course_id, grade, credit_hour, semester);
    n->gpa = n->enrolled->point;
    n->remain_credit = 140 - n->enrolled->credit;;
    

    // find the position that new node can be inserted.
    while (temp != r->nil)
    {
        p = temp;

        if (key > temp->key)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    n->p = p; // link new node to p

    if (p == r->nil)
    {
        r->r = n;
    }
    else if (key > p->key)
    {
        p->right = n;
    }
    else
    {
        p->left = n;
    }

    insert_fixup(r, n);
}

void insert_fixup(ROOT* r, NODE* x)
{
    NODE* u = NULL;;

    while ((x->p)->clr == RED)
    {
        if (x->p == (x->p->p)->left)
        {
            u = (x->p->p)->right;

            // process property 4 of the red-black properties.
            if (u->clr == RED)
            {
                (x->p)->clr = BLACK;
                u->clr = BLACK;

                (x->p->p)->clr = RED;

                x = (x->p->p);
            }
            // process property 5
            else
            {
                if (x == (x->p)->right)
                {
                    x = (x->p);

                    left_rotate(r, x);
                }

                (x->p)->clr = BLACK;
                (x->p->p)->clr = RED;

                right_rotate(r, (x->p->p));
            }
        }
        else
        {
            u = (x->p->p)->left;

            // process property 4 of the red-black properties.
            if (u->clr == RED)
            {
                (x->p)->clr = BLACK;
                u->clr = BLACK;

                (x->p->p)->clr = RED;

                x = (x->p->p);
            }
            // process property 5
            else
            {
                if (x == (x->p)->left)
                {
                    x = (x->p);

                    right_rotate(r, x);
                }

                (x->p)->clr = BLACK;
                (x->p->p)->clr = RED;

                left_rotate(r, (x->p->p));
            }
        }
    }

    // correct the lone violation of property 2.
    (r->r)->clr = BLACK;
}

void tree_transplant(ROOT* r, NODE* t, NODE* c)
{
    if (t->p == r->nil)
    {
        r->r = c;
    }
    else if (t == (t->p)->left)
    {
        (t->p)->left = c;
    }
    else
    {
        (t->p)->right = c;
    }

    c->p = t->p; // link target's parent to child's parent.
}

void delete_node(ROOT* r, int key)
{
    NODE* target = r->r; // the node that we want to remove.
    NODE* temp = NULL; // the node that is moved or removed.
    NODE* x = NULL; // temp's original position
    char t_clr;

    // find the node that has the key
    while (key != target->key)
    {
        if (target->key > key)
        {
            target = target->left;
        }
        else
        {
            target = target->right;
        }
    }
    t_clr = target->clr;

    // the target has the child on the right.
    if (target->left == r->nil)
    {
        x = target->right;
        tree_transplant(r, target, target->right);
    }
    // the target has the child on the left.
    else if (target->right == r->nil)
    {
        x = target->left;
        tree_transplant(r, target, target->left);
    }
    else
    {
        temp = target->right;

        // find the minimum key
        while (temp->left != r->nil)
        {
            temp = temp->left;
        }

        t_clr = temp->clr;
        x = temp->right;

        // because temp will move target's position,
        // temp's right child is moved temp's position.
        tree_transplant(r, temp, temp->right);
        temp->right = target->right;
        (temp->right)->p = temp;

        // temp takes target's position
        tree_transplant(r, target, temp);
        temp->left = target->left;
        (temp->left)->p = temp;
        temp->clr = target->clr;
    }

    if (t_clr == BLACK)
    {
        delete_fixup(r, x);
    }

    free(target);
}

void delete_course(ROOT* r, int key, char* course_id) {
    NODE* target = search_node(r, r->r, key);
    COURSE* temp = target->enrolled;
    COURSE* pre = target->enrolled;

    //맨 첫번째 과목일 경우
    if (temp->course_id == course_id) {
        printf("\n%s\n", temp->semester);
        printf("%s %c %d\n", temp->course_id, temp->grade, temp->credit);
        printf("[Total students %d, GPA %d]\n", getNodes(r, r->r), getTotalGPA(r, r->r));
        target->enrolled = temp->next;
        free(temp);
        return;
    }

    //아닌 경우
    while (pre->next != NULL) {
        temp = temp->next;
        if (temp->course_id == course_id) {
            printf("\n%s\n", temp->semester);
            printf("%s %c %d\n", temp->course_id, temp->grade, temp->credit);
            printf("[Total students %d, GPA %d]\n", getNodes(r, r->r), getTotalGPA(r, r->r));
            pre->next = temp->next;
            free(temp);
            return;
        }
        pre = pre->next;
    }
}

void delete_fixup(ROOT* r, NODE* x)
{
    NODE* s = NULL; // sibling node.

    while ((x != r->r) && (x->clr == BLACK))
    {
        if (x == (x->p)->left)
        {
            s = (x->p)->right;

            // case 1 : x's sibling s is red
            if (s->clr == RED)
            {
                s->clr = BLACK;
                (x->p)->clr = RED;
                left_rotate(r, x->p);
                // update x's sibling
                s = (x->p)->right;
            }

            // case 2 : x's sibling s is black, and both of s's children are black.
            if ((s->left)->clr == BLACK && (s->right)->clr == BLACK)
            {
                s->clr = RED;
                x = x->p;
            }
            // case 3 : x's sibling s is black, s's left child is red, another is black.
            else if ((s->left)->clr == RED && (s->right)->clr == BLACK)
            {
                s->clr = RED;
                (s->left)->clr = BLACK;
                right_rotate(r, s);
                // update x's sibling
                s = (x->p)->right;
            }

            // case 4 : x's sibling s is black, s's right child is red.
            if ((s->right)->clr == RED)
            {
                s->clr = (x->p)->clr;
                (s->right)->clr = BLACK;
                (x->p)->clr = BLACK;
                left_rotate(r, x->p);

                x = r->r;
            }

        }
        else
        {
            s = (x->p)->left;

            // case 1 : x's sibling s is red
            if (s->clr == RED)
            {
                s->clr = BLACK;
                (x->p)->clr = RED;
                right_rotate(r, x->p);
                // update x's sibling
                s = (x->p)->left;
            }

            // case 2 : x's sibling s is black, and both of s's children are black.
            if ((s->left)->clr == BLACK && (s->right)->clr == BLACK)
            {
                s->clr = RED;
                x = x->p;
            }
            // case 3 : x's sibling s is black, s's right child is red, another is black.
            else if ((s->right)->clr == RED && (s->left)->clr == BLACK)
            {
                s->clr = RED;
                (s->right)->clr = BLACK;
                left_rotate(r, s);
                // update x's sibling
                s = (x->p)->left;
            }

            // case 4 : x's sibling s is black, s's left child is red.
            if ((s->left)->clr == RED)
            {
                s->clr = (x->p)->clr;
                (s->left)->clr = BLACK;
                (x->p)->clr = BLACK;
                right_rotate(r, x->p);

                x = r->r;
            }
        }
    }

    x->clr = BLACK;
}

void print_tree(ROOT* r, NODE* n) {
    // 노드 n이 트리의 NIL이 아니면 n의 왼쪽 자식 노드를 출력 후 오른쪽 자식 노드를 출력
    if (n != r->nil){
        printf("%d\t", n->key);
        print_tree(r, n->left);
        printf("\n\t");
        print_tree(r, n->right);
    }
}

int getNodes(ROOT* r, NODE* n) {
    int count = 0;

    if (n != r->nil) {
        count += 1; 
        count += getNodes(r, n->left);
        count += getNodes(r, n->right);
    }
    return count;
}

void printRootKey(ROOT* r) {
    printf(" %d ", r->r->key);
    return ;
}

void printLevesKey(ROOT* r, NODE* n) {

    if (n != r->nil) {
        if (n->left == r->nil && n->right == r->nil) {
            printf(" %d ", n->key);
        }
        getLevesKey(r, n->left);
        getLevesKey(r, n->right);
    }
    return ;
}

int getHeight(ROOT* r, NODE* n) {
    int level = 0;
    if (n != r->nil) {
        level += 1;
        if (n->left != r->nil || n->right != r->nil) {
            level += max(getHeight(r, n->left), getHeight(r, n->right));
        }
    }
    return level;
}

NODE* search_node(ROOT* r, NODE* n, int key) {
    if (n != NULL){
        if (n->key == key) {
            return n;
        }
        else if (n->key < key) {
            return search_node(r, n->right, key);
        }
        else {
            return search_node(r, n->left, key);
        }
    }
    return NULL;
}

void print_info(ROOT* r, NODE* n) {

    if (n != NULL) {
        //학기별 수강과목, 학점, 시수
        COURSE* cur = n->enrolled;
        char* curSemester = cur->semester;
        printf("\n%s\n", curSemester);

        while (cur != NULL) {
            if (curSemester != cur->semester) {
                printf("\n%s\n", cur->semester);
                curSemester = cur->semester;
            }
            printf("%s %c %d\n", cur->course_id, cur->grade, cur->credit);
            cur = cur->next;
        }

        //GPA, 남은 학점
        printf("[GPA %d, Credit hours %d]\n", n->gpa, n->remain_credit);
    }
    //총 학생 수, 총 GPA 평점
    printf("[Total students %d, GPA %d]\n", getNodes(r, r->r), getTotalGPA(r, r->r));
}

int getTotalGPA(ROOT* r, NODE* n) {
    int totalGPA = 0;

    if (n != r->nil) {
        totalGPA += n->gpa;
        totalGPA += getTotalGPA(r, n->left);
        totalGPA += getTotalGPA(r, n->right);
    }
    totalGPA = totalGPA / getNodes(r, r->r);
    return totalGPA;
}

void update_info(ROOT* r, NODE* n, char* course_id, char grade, int credit_hour, char* semester) {
    COURSE* newCourse = addCourse(course_id,grade, credit_hour, semester);
    COURSE* temp = n->enrolled;
    COURSE* pre = n->enrolled;

    //비어 있는 경우
    if (temp == NULL) {
        temp = newCourse;
    }
    //맨 앞에 추가하는 경우
    else if (temp != NULL && temp->semester > semester) {
        newCourse->next = temp;
        n->enrolled = newCourse;
    }
    else {
        //중간에 추가하는 경우
        while (pre->next != NULL) {
            temp = pre->next;
            if (temp->semester >= semester) {
                pre->next = newCourse;
                newCourse->next = temp;
                break;
            }
            pre = pre->next;
        }
        //맨 뒤에 추가
        pre->next = newCourse;
    }

    int newGPA = 0;
    newGPA += (temp->credit * temp->point);
    newGPA = newGPA / (140 - n->remain_credit);
    n->gpa = newGPA;

    print_info(r, n);

    return;
}