// mapalloc.h
// Tyler J Roberts
// 30 Mar 2017
//
// For CS F321 Spring 2017
// Solution to Assignment 4 Exercise A



#ifndef FILE_MAPALLOC_H_INCLUDED
#define FILE_MAPALLOC_H_INCLUDED

#include <cstddef>
using std::size_t;

void * mapAlloc(const size_t sbyte);
void mapFree(void * addr);


#endif //#ifndef FILE_MAPALLOC_H_INCLUDED

