#include <iostream>

//void print(int** matrix, int size){
//    for(int j = 0; j < size; j++){
//        for(int i = 0; i < size; i++){
//            std::cout << matrix[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
//}

struct Node{
    int to = 0;
    Node* next = nullptr;

    Node(int t){
        to = t;
    }
};

struct ListForGraph{
    int size = 0;
    Node** arr;

    ListForGraph(int s){
        size = s;
        arr = new Node* [size];
    }

    void add(int from, int to){
        if(arr[from] == nullptr){
            arr[from] = new Node(to);
        }else{
            Node* ptr = arr[from];

            while (ptr->next != nullptr) ptr = ptr->next;
            ptr->next = new Node(to);
        }

        if(arr[to] == nullptr){
            arr[to] = new Node(from);
        }else{
            Node* ptr = arr[to];

            while (ptr->next != nullptr) ptr = ptr->next;
            ptr->next = new Node(to);
        }
    }
};

int** listToMatrix(ListForGraph* list){
    int size = list->size;
    int** matrix = new int* [size];

    for(int i = 0; i < size; i++){
        matrix[i] = new int[size];
        for(int j = 0; j < size; j++){
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < size; i++){
        Node* ptr = list->arr[i];

        while (ptr != nullptr){
            matrix[i][ptr->to] = 1;
            ptr = ptr->next;
        }
    }

    return matrix;
}

int ribsInSupplemented(ListForGraph* list){
    int size = list->size;
    int** matrix = listToMatrix(list);

    int numberOfZeros = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] == 0) numberOfZeros++;
        }
    }

    numberOfZeros -= size;
    numberOfZeros /= 2;

    return numberOfZeros;
}



//int main() {
//    const int SIZE = 4;
//
//    ListForGraph list(SIZE);
//    list.add(0, 2);
//    list.add(2, 3);
//    list.add(3, 0);
//
//    std::cout << ribsInSupplemented(&list);
//    return 0;
//}
