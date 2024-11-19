#include<iostream>
#include <cstddef>

void Insertion_sort(int* tableau,size_t size){
    if(size>1){
        for(size_t j=1;j<size;j++){
            int key =tableau[j];
            size_t i =j-1;
            while(i>0 && tableau[i]>key){
                tableau[i+1]=tableau[i];
                i=i-1;
            };
            tableau[i+1]=key;

        }

    }

}
int main() {
    int tableau[]={0,5,8,9,2,4,6};
    Insertion_sort(tableau,7);
    std::cout << tableau << std::endl;
    
    return 0;
};
