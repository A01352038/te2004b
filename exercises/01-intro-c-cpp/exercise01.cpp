// =================================================================
//
// File: exercise01.cpp
// Author(s): Sergio Augusto Macías Corona
// ID: A01352038
// Description: This file contains the code to count the number of
//				even numbers within an array. The time this implementation
//				takes will be used as the basis to calculate the
//				improvement obtained with parallel technologies.
//
// =================================================================
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <chrono>
#include "utils.h"

using namespace std;
using namespace std::chrono;

// implement your code

int main(int argc, char* argv[]) {
	int *array, result, tam;
    cout << "Tamano del arreglo --->: "; cin>>tam;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	array = new int[tamano];
    for(int i = 0; i<tam; i++){
        int n;
        cout<<"Inserte un numero ---> "<<i +1<<": "; cin>>n;
        array[i] = n;
    }
	display_array("array", array, tamano);

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < tam; j++) {
		start = high_resolution_clock::now();

		// call the implemented function
        if(array[j]%2==0){
          	result = result + array[j];
    	}

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << result << "\n";
	cout << "avg time = " << fixed << setprecision(7) 
		 << (timeElapsed / N) <<  " ms\n";

	delete [] array;
	return 0;
}
