//#include "pch.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void copyArray(int* arr, int*& arr2, int n) {
	for (int i = 0; i < n; i++) {
		arr2[i] = arr[i];
	}
}
// Standard constructor
SegmentTree::SegmentTree(segmentType sentArr[], int as, int typ) {
	arraySize = as;
	segSize = 2 * pow(2, ceil(log2(as))) - 1;
	segArray = new segmentType[segSize];
	sentArray = new int[arraySize];
	copyArray(sentArr, sentArray, arraySize); // deep copy
	treeType = typ;
	this->build(0, as - 1, 0);
}
// Copy constructor
SegmentTree::SegmentTree(const SegmentTree& ntree) {
	if (ntree.arraySize != NULL) {
		arraySize = ntree.arraySize;
		segSize = ntree.segSize;
		segArray = new segmentType[segSize];
		sentArray = new int[arraySize];
		copyArray(ntree.sentArray, sentArray, arraySize); // deep copy
		treeType = ntree.treeType;
		this->build(0, arraySize - 1, 0);
	}
}

void SegmentTree::operator=(const SegmentTree& ntree) {
	if (ntree.arraySize != NULL) {
		arraySize = ntree.arraySize;
		segSize = ntree.segSize;
		segArray = new segmentType[segSize];
		sentArray = new int[arraySize];
		for (int i = 0; i < arraySize; i++) {
			sentArray[i] = ntree.sentArray[i];
		}
		treeType = ntree.treeType;
		this->build(0, arraySize - 1, 0);
	}
}


int getMid(int start, int end) {
	return start + (end - start) / 2;
}

int getMinn(int x, int y) {
	return (x < y) ? x : y;
}
int SegmentTree::build(int start, int end, int index) {
	if (start == end) {
		segArray[index] = sentArray[start];
		return sentArray[start];
	}
	int mid = getMid(start, end);
	if (treeType == 1) {
		segArray[index] = build(start, mid, index * 2 + 1) + build(mid + 1, end, index * 2 + 2);
	}
	else if (treeType == 2) {
		segArray[index] = getMinn(build(start, mid, index * 2 + 1), build(mid + 1, end, index * 2 + 2));
	}
	return segArray[index];
}

void SegmentTree::updateValue(int i, int new_val) {
	if (i < 0 || i > arraySize - 1) {
		cout << "Invalid Input" << endl;
		return;
	}

	sentArray[i] = new_val;
	this->build(0, arraySize - 1, 0);
}

int SegmentTree::getSum(int from, int to) {
	if (from < 0 || to > arraySize - 1 || from > to) {
		cout << "Invalid Input" << endl;
		return -1;
	}
	return getSumUtil(0, arraySize - 1, from, to, 0);
}


int SegmentTree::getSumUtil(int start, int end, int from, int to, int ind) {
	if (from <= start && to >= end)
		return segArray[ind];
	if (end < from || start > to)
		return 0;
	int mid = getMid(start, end);
	return getSumUtil(start, mid, from, to, 2 * ind + 1) + getSumUtil(mid + 1, end, from, to, 2 * ind + 2);
}

void SegmentTree::insert(int value) {
	arraySize++;
	int* narr = new int[arraySize];
	for (int i = 0; i < arraySize; i++) {
		narr[i] = sentArray[i];
	}
	narr[arraySize - 1] = value;
	delete sentArray;
	sentArray = new int[arraySize];
	copyArray(narr, sentArray, arraySize);
	delete narr;
	this->build(0, arraySize - 1, 0);
}

int SegmentTree::getMinUtil(int start, int end, int from, int to, int index) {
	if (from <= start && to >= end)
		return segArray[index];

	if (end < from || start > to)
		return INT_MAX;

	int mid = getMid(start, end);
	return getMinn(getMinUtil(start, mid, from, to, 2 * index + 1),
		getMinUtil(mid + 1, end, from, to, 2 * index + 2));
}

int SegmentTree::getType() {
	return treeType;
}

int SegmentTree::getMin(int from, int to) {
	if (from < 0 || to > arraySize - 1 || from > to) {
		cout << "Invalid Input" << endl;
		return -1;
	}
	return getMinUtil(0, arraySize - 1, from, to, 0);
}

void SegmentTree::display() {
	for (int i = 0; i < this->segSize; i++) {
		if (segArray[i] > -8421504) {
			cout << segArray[i] << endl;
		}
	}
}

SegmentTree::~SegmentTree() {
	delete segArray;
	delete sentArray;
	arraySize = NULL;
	segSize = NULL;
	treeType = NULL;
}
