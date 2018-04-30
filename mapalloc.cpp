// mapalloc.cpp
// Tyler J Roberts
// 30 Mar 2017
//
// For CS F321 Spring 2017
// Solution to Assignment 4 Exercise A

#include "mapalloc.h"
#include <sys/mman.h>
#include <cstddef>
using std::size_t;
#include <vector>
using std::vector;
#include <tuple>
using std::tuple;
using std::get;
using std::make_tuple;
#include <iostream>
using std::cout;
using std::endl;
vector<tuple<void *,int>> addressTable;

void * mapAlloc(const size_t sbyte){

	void * addr = mmap(nullptr,sbyte,PROT_WRITE,MAP_SHARED,-1, 0);
    if(addr == MAP_FAILED){
    	return nullptr;
    }
    addressTable.push_back(make_tuple(addr,sbyte));
    return addr;
}

void mapFree(void * addr){
	for(size_t i = 0; i < addressTable.size();i++){
		if(get<0>(addressTable[i])==addr){
			munmap(addr,get<1>(addressTable[i]));
			addressTable.erase(addressTable.begin()+i,addressTable.begin()+i+1);
		}
	}
}

