#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void enqueue(vector<int> &mainStack, vector<int> &suppStack, int element){
    while(!mainStack.empty()){
        int iter = mainStack.back();
        suppStack.push_back(iter);
        mainStack.pop_back();
    }
    mainStack.push_back(element);
    while(!suppStack.empty()){
        int iter = suppStack.back();
        mainStack.push_back(iter);
        suppStack.pop_back();
    }
}

/**
* @brief Removes the element at the end of the vector \ a mainstack. This is useful for dequeuing a vector of integers to an int vector
* @param mainstack The vector to dequeue
*/
void dequeue(vector<int> &mainstack){
    // If the mainstack is empty return.
    if (mainstack.empty()){
        return;
    }
    mainstack.pop_back();
}

/**
* @brief This function is called when the program starts. All input is read from standard input and the output is written to standard output.
* @return Returns 0 on success 1 on failure. In this case you should exit the program with an error code
*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    int queries, opn, element;
    vector<int> mainStack;
    vector<int> suppStack;
    cin>>queries; 
    for(int i=0; i<queries; i++){
        cin>>opn;
        // The main stack is the front of the stack.
        if (opn==1){
            cin>>element;
            enqueue(mainStack, suppStack, element);
        }
        // Dequeue the main stack if opn 2.
        else if (opn==2){
            dequeue(mainStack);
        }
        else{
            cout<<mainStack.back()<<endl;
        }
    }
    return 0;
}
