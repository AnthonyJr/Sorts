//
//  main.cpp
//  Homework8
//
//  Created by Anthony Snow on 11/24/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <time.h>       /* time */



using namespace std;
int showMenu1();
int showMenu2();
void selection_sort(vector<int> vector);
void selection_sort(vector<int> vector, int & count);

void insertion_sort(vector<int> vector);
int  partition(vector<int> &v,int pivot, int left, int right, int &count);
void quicksort_random(vector<int> vector);
void doQSort(vector<int> & vector, int low, int high, int &count);
int partition(vector<int> &vector, int pivot, int left, int right, int & count);
void quicksort_first(vector<int> vector);
void merge_sort(vector<int> vector);
vector<int> doMSort(vector<int> vector);
vector<int> merge(vector<int> left , vector<int> right);

void rand50();

vector<int> generateRandomVec();
vector<int> generateManual();
vector<int>  generateReverseSorted();
vector<int> generateSwap();
void swap(int &a, int &b);


int main(int argc, const char * argv[]) {
    vector<int> V;
    int input;

    int choice1;
    int choice2;
    cout << "How would you like to generate Numbers? " << endl;
    choice1 = showMenu1();
    switch (choice1) {
        case 1:
            cout << "You want to manually Enter Nubmers!" << endl;
            V = generateManual();
            
            break;
        case 2:
            cout << "you want to random generate numbers " << endl;
            V = generateRandomVec();
            break;
        case 3:
            cout << "Reserve sorted order " << endl;
            V = generateReverseSorted();
        case 4:
            cout << "Swapped" << endl;
            V = generateSwap();
            

            
        default:
            cout << "Invalid Option " << endl;
            break;
    }
    

    cout << "Which sorting method would you like to use?" << endl;
    cin.clear();
    cin.ignore();
    choice2 = showMenu2();
    switch (choice2) {
        case 1:
            cout << "You chose Selection Sort! Excellent!" << endl;
            selection_sort(V);
            break;
        case 2:
            cout << "You chose Insertion Sort! Sweet " << endl;
            insertion_sort(V);
            break;
        case 3:
            cout << "You chose Quicksort with random pivot! " << endl;
            quicksort_random(V);
            break;
        case 4:
            cout << "You chose Quicksort with first pivot!" << endl;
            break;
        case 5:
            cout << "You chose Mergesort! " << endl;
            break;
        case 6:
            cout << "Random Number Test (50) Times " << endl;
            
        default:
            cout << "Invalid Option " << endl;
            break;
    }
}


int showMenu1(){
    int x;
    cout << "1. Manually Enter Numbers " << endl;
    cout << "2. Generate Numbers Randomly " << endl;
    cout << "3. Generate Reverse Order " << endl;
    cout << "4. Generate Swapping of Consecutive Pairs " << endl;
    cin >> x;
    return x;
}

int showMenu2(){
    int x;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Quicksort with the random selection of a pivot" << endl;
    cout << "4. Quicksort that chooses first element as pivot" << endl;
    cout << "5. Mergesort" << endl;
    cin >> x;
    return x;
}




vector<int> generateRandomVec(){
    srand (time(NULL));
    vector<int> V;
    int n;
    int k;
    cout << "How many numbers? " << endl;
    cin >> n;

    cout << "How many digits? " << endl;
    cin >> k;
    
    for (int i = 0; i < n; i++) {
        V.push_back(rand() % (int) pow(10.0, k) - 1);
    }
    
    cout << "The vector contains:";
    for (vector<int>::iterator it = V.begin(); it!= V.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;

    return V;
}

vector<int> generateManual(){
    int input;
    vector<int> V;
    while (cin >> input){
        V.push_back(input);
    }
    
    cout << "The vector contains:";
    for (vector<int>::iterator it = V.begin(); it!= V.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
    
    return V;
    
}

vector<int>  generateReverseSorted(){
    vector<int> V;
    cout << "Up to what number?" << endl;
    int n;
    cin >> n;
    for (int i = n; i > 0 ; i--) {
        V.push_back(i);
    }
    cout << "The vector contains:";
    for (vector<int>::iterator it = V.begin(); it!= V.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
    return V;
}

vector<int> generateSwap(){
    int pair1;
    int pair2;
    vector<int> V;
    cout << "Up to what number? " << endl;
    int n;
    cin >> n;
    for (int i = 1; i <=n; i+=2) {
        V.push_back(i+1);
        V.push_back(i);
    }
    cout << "The vector contains:";
    for (vector<int>::iterator it = V.begin(); it!= V.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
    return V;
    
}

void selection_sort(vector<int> vector){
    int i,j,n;
    int compares = 0;
    for (j = 0; j<vector.size() -1 ; j++) {
        compares++;
        int min = j;
        for (i = j+1 ; i< vector.size(); i++) {
            
            if (vector[i] < vector[min]) {
                min = i;
            }
        }
        
        if (min !=j) {
            iter_swap(vector.begin() + j, vector.begin() + min);
        }
    }
    
    cout << "=========================================" << endl;
    cout << "Statistics: " << endl;
    cout << "The sortred vector: ";
    for (int k = 0; k < vector.size() ; k++) {
        cout << " " << vector[k];
    }
    cout << endl;
    cout << "Number of compares: " << compares << endl;
    cout << "==========================================" << endl;
}




void insertion_sort(vector<int> vector){
    int compares;
    int x,k,j;
    for (int i = 0; i<vector.size(); i++) {
        x = vector[i];
        j = i-1;
        compares++;
        while (j >=0 && vector[j] > x) {
            vector[j+1] = vector[j];
            j = j-1;
        }
        vector[j+1] = x;
    }
    cout << "=========================================" << endl;
    cout << "Statistics: " << endl;
    cout << "The sortred vector: ";
    for (int k = 0; k < vector.size() ; k++) {
        cout << " " << vector[k];
    }
    cout << endl;
    cout << "Number of compares: " << compares << endl;
    cout << "==========================================" << endl;
}

void quicksort_random(vector<int> vector){
    // actually do the quicksort in this function; set everything up.
    int left = 0;
    int right = vector.size() -1;
    int compares = 0;
    doQSort(vector, left, right, compares);

    
    cout << "=========================================" << endl;
    cout << "Statistics: " << endl;
    cout << "The sortred vector: ";
    for (int k = 0; k < vector.size() ; k++) {
        cout << " " << vector[k];
    }
    cout << endl;
    cout << "Number of compares: " << compares << endl;
    cout << "==========================================" << endl;
    
    
}

void doQSort(vector<int> & vector, int low, int high, int &count){
    if (low < high) {
        int pivot = floor((low+high)/2);
        int j = partition(vector, pivot, low, high, count);
        doQSort(vector, low, j-1, count);
        doQSort(vector, j+1, high, count);
        
    }
}

int partition(vector<int> &vector, int pivot, int left, int right, int & count){
    int x = vector[pivot];
    iter_swap(vector.begin() + pivot, vector.begin() + right);
    int j = left;
    
    for (int i  = left; i< right; i++) {
        count++;
        if (vector[i] <= x) {
            iter_swap(vector.begin() + i, vector.begin() + j);
            j++;
        }
    }
    iter_swap(vector.begin() + j, vector.begin() + right);
    return j;
}


void merge_sort(vector<int> vector){

    
    
    int left = 0;
    int right = vector.size() -1;
    int compares = 0;
    //vector = doMSort(vector);
    
    
    
    
}


vector<int> doMSort(vector<int> vector){

    if (vector.size() <= 1) {
        return vector;
    }
    
    std::vector<int>::iterator middle = vector.begin() + (vector.size() /2);


    
    
    
    return vector;
}

vector<int>  merge(vector<int> left , vector<int> right){
    return left;
}








