//+++++++++++++++++++++++++++++++++++++++++++++++
// Author: Luis Chaparro
// Homework: 1
// Date: 05/31/2016
// Description: Both programs are included, 
// 				top one is with write() & read() 
//				bottom one is fwrite() & fread()
//+++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main(){
	
	int size = 1000;
	ifstream a("dummies/fileA.txt", ifstream::in);
	ofstream b("dummies/fileB.txt", ofstream::out);
	ofstream c("copying.txt", ofstream::out);
	c << "\n\n++++++ fwrite() & fread() ++++++\n\n";
	while (!a.eof() || size <= 100000000){
		clock_t begin = clock();		
		char* buffer = new char[size];
		
		a.fread(buffer, size); //reading from file A
		b.fwrite(buffer, size); //writing to file B
		cout << size/1000 << " KB" << endl;
		size *= 2;
		delete[] buffer;
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		c << size/1000 << "KB to0k: " << elapsed_secs << endl << endl;
	}
	a.close();
	b.close();
	c.close();
	return 0;
}
/*
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){	
	int size = 1000;
	size_t result;
	ofstream c;
	
	FILE * a;
	FILE * b;
	c.open("copying.txt", ofstream::out | ofstream::app);
	c << "\n\n++++++ fwrite() & fread() ++++++\n\n";
	while (size <= 100000000){
		clock_t begin = clock();		
		a = fopen("dummies/fileA.txt", "r" );
		b = fopen("dummies/fileB.txt", "w");
		if (a == NULL || b == NULL){fputs ("File error",stderr); exit (1);}
		
		char* buffer = (char*)malloc (sizeof(char)*size);
		if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
		
		result = fread(buffer, 1, size, a);
		//if (result != size) {fputs ("Reading error",stderr); exit (3);}
		
		result = fwrite(buffer, 1, size, b);
		//if (result != size) {fputs ("Reading error",stderr); exit (4);}
		
		cout << size/1000 << " KB" << endl;
		size *= 2;
		free (buffer);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		c << size/1000 << "KB took: " << elapsed_secs << endl << endl;
	}
	fclose(a);
	fclose(b);
	c.close();
	return 0;
}*/