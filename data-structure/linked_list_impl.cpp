#include <iostream>

struct node{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE head = NULL;

void displayEntries(std::string header){
    NODE ptr = head;
    if (ptr == NULL) {
        std::cout << "Warning: Recieved empty list" << "\n\n";
        return;
    }
    std::cout << "\n" << header << "\n";
    while (ptr != NULL) {
        printf("Data = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void createList(int n){ 
    int entry;
    NODE tran, last;
    for (int i = 1; i <= n; i++){
        printf("Input data for node %d : ", i);
        std::cin >> entry;
        last = new node;
        last->data = entry;
        last->next = NULL;
        if (head == NULL) head = last;
        else {
            for (tran = head; tran->next != NULL; tran=tran->next);
            tran->next = last; 
        }
    }
}

void displayList(){
    displayEntries("Data entered in the list :");
}

void insertFront(int n){
    NODE con = new node;
    con->data = n;
    con->next = head;
    head = con;
    displayEntries("Data after inserted in the list are :");
}

void insertLast(int n){
    NODE tran, last;
    last = new node;
    last->data = n;
    last->data = n;
    last->next = NULL;
    if (head == NULL) head = last;
    last->next = NULL;
    if (head == NULL) head = last;
    else {
        for (tran = head; tran->next != NULL; tran=tran->next);
        tran->next = last; 
    }
    displayEntries("Data, after inserted in the list are :");
}

void insertMiddle(int n, int pos){
    NODE cur = head;
    for (int i = 1; i < pos - 1 && cur->next != NULL; i++) cur = cur->next;
    if (cur == NULL){
        std::cout << "Error: Null pointer" << "\n";
        return;
    }
    NODE con = cur->next, tran = new node;
    tran->data = n;
    tran->next = con;
    cur->next = tran;
    displayEntries("Insertion completed successfully.\n\nThe new list are :");
}

bool checkHead(NODE ptr, std::string name){
    bool isNull = ptr == NULL;
    if (isNull) std::cout << "[" << name << "]" << " Error: Null node\n";
    return isNull;
}

void deleteFront(){
    NODE ptr = head;
    if (checkHead(ptr, "deleteFront")) return;
    head = ptr->next;
    int data = ptr->data;
    delete ptr;
    printf("\nData of node 1 which is being deleted is : %d\n\n", data);
    displayEntries("Data, after deletion of first node :");
}

void deleteLast(){
    NODE ptr = head, last;
    if (checkHead(ptr, "deleteLast")) return;
    while(ptr->next->next != NULL) ptr = ptr->next;
    last = ptr->next;
    ptr->next = NULL;
    delete last;
    displayEntries("The new list after deletion the last node are :");
}

void deleteMiddle(int pos){
    int walk = 1;
    bool exceed = false;
    NODE ptr = head, prev, tar;
    if (ptr == NULL) goto print;
    if (ptr->next == NULL) {
        delete ptr;
        goto print;
    }
    if (pos == 1){
        head = ptr->next;
        delete ptr;
        goto print;
    }
    while(ptr != NULL){
        if (walk++ == pos){
            tar = prev->next;
            prev->next = tar->next;
            delete tar;
            goto print;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    exceed = true;
    print:
        displayEntries(exceed ? "Warning: Position out of range" : "Deletion completed successfully.\n\nThe new list are :");
}

int searchList(int n){
    NODE ptr = head;
    for (int i = 1; ; i++){
        if (ptr->data == n) return i;
        if (ptr->next == NULL) break;
        ptr = ptr->next;
    }
    return -1;
}

// driver
int main(){
    int n, entry, entry2;

    std::cout << "Input the number of nodes : ";
    std::cin >> n;
    createList(n);
    displayList();

    //* -- 2nd task

    std::cout << "\nInput data to insert at the beginning of the list : ";
    std::cin >> entry;
    insertFront(entry);

    std::cout << "\nInput data to insert at the end of the list : ";
    std::cin >> entry;
    insertLast(entry);

    std::cout << "\nInput data to insert in the middle of the list : "; std::cin >> entry;
    std::cout << "Input the position to insert new node : "; std::cin >> entry2;
    insertMiddle(entry, entry2);

    //*/

    //* -- 3rd task

    deleteFront();
    deleteLast();

    std::cout << "\nInput the position of node to delete : "; std::cin >> entry;
    deleteMiddle(entry);
    //*/

    //* -- 4th task
    std::cout << "\nInput the element to be searched : "; std::cin >> entry;
    int idx = searchList(entry);
    if (idx + 1) printf("Data found at node %d\n", idx);
    else std::cout << "Data not found :(" << "\n\n";
    //*/

    return 0;
}