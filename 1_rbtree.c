#include "header.h"

void create_nilnode(TOTAL* r)
{
    r->nil = (STUDENT*)malloc(sizeof(STUDENT));
    (r->nil)->color = BLACK;
    r->r = r->nil;
}

void left_rotate(TOTAL* r, STUDENT* x)
{
    STUDENT* temp;

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
void right_rotate(TOTAL* r, STUDENT* y)
{
    STUDENT* temp;

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

void insert_fixup(TOTAL* r, STUDENT* x)
{
    STUDENT* u = NULL;;

    while ((x->p)->color == RED)
    {
        if (x->p == (x->p->p)->left)
        {
            u = (x->p->p)->right;

            // process property 4 of the red-black properties.
            if (u->color == RED)
            {
                (x->p)->color = BLACK;
                u->color = BLACK;

                (x->p->p)->color = RED;

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

                (x->p)->color = BLACK;
                (x->p->p)->color = RED;

                right_rotate(r, (x->p->p));
            }
        }
        else
        {
            u = (x->p->p)->left;

            // process property 4 of the red-black properties.
            if (u->color == RED)
            {
                (x->p)->color = BLACK;
                u->color = BLACK;

                (x->p->p)->color = RED;

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

                (x->p)->color = BLACK;
                (x->p->p)->color = RED;

                left_rotate(r, (x->p->p));
            }
        }
    }

    // correct the lone violation of property 2.
    (r->r)->color = BLACK;
}
void insert_node(TOTAL* r, int student_id, ENROLL* new_infos){

    STUDENT* temp = r->r;
    STUDENT* p = r->nil;
    STUDENT* n = create_student(r, student_id, new_infos);

    while (temp != r->nil){
        p = temp;

        if (n->student_id > temp->student_id){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }

    n->p = p;

    if (p == r->nil){
        r->r = n;
    }else if (n->student_id > p->student_id){
        p->right = n;
    }else{
        p->left = n;
    }

    insert_fixup(r, n);
    print_rb_info(r, n);
}

void tree_transplant(TOTAL* r, STUDENT* t, STUDENT* c)
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
void delete_fixup(TOTAL* r, STUDENT* x)
{
    STUDENT* s = NULL; // sibling node.

    while ((x != r->r) && (x->color == BLACK))
    {
        if (x == (x->p)->left)
        {
            s = (x->p)->right;

            // case 1 : x's sibling s is red
            if (s->color == RED)
            {
                s->color = BLACK;
                (x->p)->color = RED;
                left_rotate(r, x->p);
                // update x's sibling
                s = (x->p)->right;
            }

            // case 2 : x's sibling s is black, and both of s's children are black.
            if ((s->left)->color == BLACK && (s->right)->color == BLACK)
            {
                s->color = RED;
                x = x->p;
            }
            // case 3 : x's sibling s is black, s's left child is red, another is black.
            else if ((s->left)->color == RED && (s->right)->color == BLACK)
            {
                s->color = RED;
                (s->left)->color = BLACK;
                right_rotate(r, s);
                // update x's sibling
                s = (x->p)->right;
            }

            // case 4 : x's sibling s is black, s's right child is red.
            if ((s->right)->color == RED)
            {
                s->color = (x->p)->color;
                (s->right)->color = BLACK;
                (x->p)->color = BLACK;
                left_rotate(r, x->p);

                x = r->r;
            }

        }
        else
        {
            s = (x->p)->left;

            // case 1 : x's sibling s is red
            if (s->color == RED)
            {
                s->color = BLACK;
                (x->p)->color = RED;
                right_rotate(r, x->p);
                // update x's sibling
                s = (x->p)->left;
            }

            // case 2 : x's sibling s is black, and both of s's children are black.
            if ((s->left)->color == BLACK && (s->right)->color == BLACK)
            {
                s->color = RED;
                x = x->p;
            }
            // case 3 : x's sibling s is black, s's right child is red, another is black.
            else if ((s->right)->color == RED && (s->left)->color == BLACK)
            {
                s->color = RED;
                (s->right)->color = BLACK;
                left_rotate(r, s);
                // update x's sibling
                s = (x->p)->left;
            }

            // case 4 : x's sibling s is black, s's left child is red.
            if ((s->left)->color == RED)
            {
                s->color = (x->p)->color;
                (s->left)->color = BLACK;
                (x->p)->color = BLACK;
                right_rotate(r, x->p);

                x = r->r;
            }
        }
    }

    x->color = BLACK;
}
void delete_node(TOTAL* r, int student_id)
{
    STUDENT* target = r->r; // the node that we want to remove.
    STUDENT* temp = NULL; // the node that is moved or removed.
    STUDENT* x = NULL; // temp's original position
    char t_clr;

    // find the node that has the key
    while (student_id != target->student_id)
    {
        if (target->student_id > student_id)
        {
            target = target->left;
        }
        else
        {
            target = target->right;
        }
    }
    t_clr = target->color;

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

        t_clr = temp->color;
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
        temp->color = target->color;
    }

    if (t_clr == BLACK)
    {
        delete_fixup(r, x);
    }
    print_rb_info(r, target);
    free(target);
}

//=============================================================================

STUDENT* create_student(TOTAL* r, int student_id, ENROLL* new_infos)
{
    STUDENT* n = (STUDENT*)malloc(sizeof(STUDENT));
    STUDENT* temp = r->r;
    STUDENT* p = r->nil;

    n->left = r->nil;
    n->right = r->nil;
    n->color = RED;

    n->student_id = student_id;
    n->registered = NULL;
    n->myGPA = 0;
    n->complete_credits = 0;

    return n;
}
STUDENT* search_student(TOTAL* r, STUDENT* n, int student_id) {
    if (n != NULL) {
        if (n->student_id == student_id) {
            return n;
        }else if (n->student_id < student_id) {
            return search_student(r, n->right, student_id);
        }else {
            return search_student(r, n->left, student_id);
        }
    }
    return NULL;
}

int get_total_students(TOTAL* r, STUDENT* n) {
    int count = 0;

    if (n != r->nil) {
        count += 1;
        count += get_total_students(r, n->left);
        count += get_total_students(r, n->right);
    }
    return count;
}
int get_point(char grade) {
    if (grade == 'A') {
        return 4;
    }else if (grade == 'B') {
        return 3;
    }else if (grade == 'C') {
        return 2;
    }else if (grade == 'D') {
        return 1;
    }else if (grade == 'F') {
        return 0;
    }
}
float get_total_GPA(TOTAL* r, STUDENT* n) {
    float totalGPA = 0;

    if (n != r->nil) {
        totalGPA += n->myGPA;
        totalGPA += get_total_GPA(r, n->left);
        totalGPA += get_total_GPA(r, n->right);
    }
    totalGPA = totalGPA / get_total_students(r, r->r);
    return totalGPA;
}

void print_leves_key(TOTAL* r, STUDENT* n) {

    if (n != r->nil) {
        if (n->left == r->nil && n->right == r->nil) {
            printf(" %d ", n->student_id);
        }
        print_leves_key(r, n->left);
        print_leves_key(r, n->right);
    }
    return;
}
int get_height(TOTAL* r, STUDENT* n) {
    int level = 0;
    if (n != r->nil) {
        level += 1;
        if (n->left != r->nil || n->right != r->nil) {
            level += max(get_height(r, n->left), get_height(r, n->right));
        }
    }
    return level;
}

void print_rb_info(TOTAL* r, STUDENT* n) {

    printf("\nTotal number of the nodes: %d\n", get_total_students(r, r->r));
    printf("The key value of root: %d\n", r->r->student_id);
    printf("The key valus of leaves: ");
    print_leves_key(r, r->r);
    printf("\nThe height of the tree: %d\n", get_height(r, r->r));
}
void print_student_info(TOTAL* r, STUDENT* n) {

    SEMESTER* temp = n->registered;
    float curGPA = 0;
    int curCount = 0;

    //학기별 수강과목, 학점, 시수
    while (temp != NULL) {
        printf("\n%s\n", temp->semeseter_info);

        ENROLL* taken = temp->courses;
        while (taken != NULL) {
            curGPA += get_point(taken->grade);
            curCount += 1;
            printf("%s %c %d\n", taken->course_id, taken->grade, taken->credit);
            taken = taken->next;
        }
        temp = temp->next;
    }
    //GPA, 남은 학점
    curGPA = curGPA / curCount;
    n->myGPA = curGPA;
    n->complete_credits = curCount;
    printf("[GPA %.2f, Credit hours %d]\n", curGPA, 140 - curCount);

    //총 학생 수, 총 GPA 평점
    printf("[Total students %d, GPA %.2f]\n", get_total_students(r, r->r), get_total_GPA(r, r->r));
}

