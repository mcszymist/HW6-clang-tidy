// randacc.cpp
// Tyler J Roberts
// 30 Mar 2017
//
// For CS F321 Spring 2017
// Solution to Assignment 4 Exercise B

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstddef>
using std::size_t;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

//Takes multiply user inputs to store data on a file using mmap in 4 byte chucks aka 32-bit Int.

int main(){
    string options;
    int optionn;
    int data;
    const size_t sbytes = 400;
    int fd = open("csrecords.txt", O_RDWR);
    if (fd == -1)
    {
        cout << "Error: file couldnt be opened." << endl;
        return 1;
    }
    void * addr = mmap(nullptr, sbytes,
                   PROT_READ | PROT_WRITE,  // We only read the file (say)
                   MAP_SHARED,
                   fd, 0);
    if (addr == MAP_FAILED)
    {
        cout << "Error: memory couldnt be mapped." << endl;
        close(fd);
        return 1;
    }
    int * recordArray = (int *)(addr);

    while(true){
    	cout << "1. Read a record" << endl;
    	cout << "2. Write a record" << endl;
    	cout << "3. Quit" << endl;
    	getline(cin,options);
    	int optionn = stoi(options,nullptr,10);
        switch(optionn)                                                                                                         
        {
        case 1:
            cout << "Enter the Index of record:";
            getline(cin,options);                   
    	    optionn = stoi(options,nullptr,10);
    	    cout << "Record: "<<optionn;
    	    optionn*=4;
    	    cout << " is " << recordArray[optionn] << endl;
            break;
        case 2:
            cout << "Enter the Index of record:";
            getline(cin,options);
    	    optionn = stoi(options,nullptr,10)*4;
    	    
    	    cout << "Enter the data you wish to save: ";
    	    getline(cin,options);
    	    data = stoi(options,nullptr,10);
    	    recordArray[optionn] = data;
            break;
        case 3:
            munmap(addr, sbytes);
            close(fd);
            cout << "GoodBye!" << endl;
            return 0;
            break;
        default:
           cout << endl << "Error enter a vaild number: ";
        }
    }
}