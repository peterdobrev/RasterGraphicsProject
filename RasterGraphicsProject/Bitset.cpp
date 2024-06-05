#include "Bitset.h"

BitSet::BitSet(unsigned N)
{
	bucketsCount = N / elementsInBucket + 1;
	buckets = new uint8_t[bucketsCount]{ 0 };
	this->N = N;
}

void BitSet::free()
{
	delete[] buckets;//!!!
	bucketsCount = 0;
	buckets = nullptr;
}
void BitSet::copyFrom(const BitSet& other)
{
	buckets = new uint8_t[other.bucketsCount];
	for (size_t i = 0; i < other.bucketsCount; i++)
		buckets[i] = other.buckets[i];
	bucketsCount = other.bucketsCount;
	N = other.N;
}

BitSet::BitSet(const BitSet& other)
{
	copyFrom(other);
}
BitSet& BitSet::operator=(const BitSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
BitSet::~BitSet()
{
	free();
}

unsigned BitSet::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;
}

void BitSet::turnOnBit(unsigned num)
{
	if (num > N)
		return;

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = 1 << bitIndex;
	buckets[bucketIndex] |= mask;

}

void BitSet::turnOffBit(unsigned num)
{

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = ~(1 << bitIndex);
	buckets[bucketIndex] &= mask;
}

bool BitSet::getBit(unsigned num) const
{
	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = 1 << bitIndex;

	return buckets[bucketIndex] & mask;
}

unsigned BitSet::getN() const
{
	return N;
}

void BitSet::print() const
{
	std::cout << '{';
	for (int i = 0; i <= N; i++)
	{
		if (getBit(i))
			std::cout << i << " ";
	}

	std::cout << '}' << std::endl;
}

BitSet UnionOfSets(const BitSet& lhs, const BitSet& rhs)
{
	BitSet result(std::max(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (int i = 0; i < minBucketsCount; i++)
		result.buckets[i] = lhs.buckets[i] | rhs.buckets[i];

	const BitSet& biggerN = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs; //no copy here

	for (int i = minBucketsCount; i < biggerN.bucketsCount; i++)
		result.buckets[i] = biggerN.buckets[i];
	return result;
}

BitSet IntersectionOfSets(const BitSet& lhs, const BitSet& rhs)
{
	BitSet result(std::min(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (int i = 0; i < minBucketsCount; i++)
		result.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	return result;
}