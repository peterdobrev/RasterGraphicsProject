#pragma once
#include <iostream>

class BitSet
{
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const BitSet& other);

	unsigned getBucketIndex(unsigned num) const;
public:
	BitSet(unsigned n);
	BitSet() : BitSet(0) {}

	BitSet(const BitSet& other);
	BitSet& operator=(const BitSet& other);
	~BitSet();

	void turnOnBit(unsigned num);
	void turnOffBit(unsigned num);
	bool getBit(unsigned num) const;
	bool operator[](unsigned num) const;
	unsigned getN() const;
	void print() const;
	friend BitSet UnionOfSets(const BitSet& lhs, const BitSet& rhs);
	friend BitSet IntersectionOfSets(const BitSet& lhs, const BitSet& rhs);

};