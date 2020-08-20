#pragma once
#include <iostream>
using namespace std;
#ifndef SEGMENTTREE
#define SEGMENTTREE

typedef int segmentType;

class SegmentTree {
public:
	SegmentTree(segmentType[], int, int);
	SegmentTree(const SegmentTree&);
	void operator=(const SegmentTree&);
	int build(int, int, int);
	int getSum(int, int);
	int getSumUtil(int, int, int, int, int);
	segmentType* getTree();
	void updateValue(int, int);
	int getMin(int, int);
	int getMinUtil(int, int, int, int, int);
	void insert(int);
	void deleteIndex(int);
	void display();
	int getType();
	~SegmentTree();
private:
	int arraySize;
	int segSize;
	int treeType;
	segmentType* sentArray;
	segmentType* segArray;
};

#endif
