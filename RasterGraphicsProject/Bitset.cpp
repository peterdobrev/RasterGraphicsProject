#include "Bitset.h"

Bitset::Bitset(unsigned N)
{
	bucketsCount = N / elementsInBucket + 1;
	buckets = new uint8_t[bucketsCount]{ 0 };
	this->N = N;
}

void Bitset::free()
{
	delete[] buckets;//!!!
	bucketsCount = 0;
	buckets = nullptr;
}
void Bitset::copyFrom(const Bitset& other)
{
	buckets = new uint8_t[other.bucketsCount];
	for (size_t i = 0; i < other.bucketsCount; i++)
		buckets[i] = other.buckets[i];
	bucketsCount = other.bucketsCount;
	N = other.N;
}

Bitset::Bitset(const Bitset& other)
{
	copyFrom(other);
}
Bitset& Bitset::operator=(const Bitset& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Bitset::~Bitset()
{
	free();
}

unsigned Bitset::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;
}

void Bitset::add(unsigned num)
{
	if (num > N)
		return;

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = 1 << bitIndex;
	buckets[bucketIndex] |= mask;

}

void Bitset::remove(unsigned num)
{

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = ~(1 << bitIndex);
	buckets[bucketIndex] &= mask;
}

bool Bitset::contains(unsigned num) const
{
	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = 1 << bitIndex;

	return buckets[bucketIndex] & mask;
}

void Bitset::print() const
{
	std::cout << '{';
	for (int i = 0; i <= N; i++)
	{
		if (contains(i))
			std::cout << i << " ";
	}

	std::cout << '}' << std::endl;
}

Bitset UnionOfSets(const Bitset& lhs, const Bitset& rhs)
{
	Bitset result(std::max(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (int i = 0; i < minBucketsCount; i++)
		result.buckets[i] = lhs.buckets[i] | rhs.buckets[i];

	const Bitset& biggerN = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs; //no copy here

	for (int i = minBucketsCount; i < biggerN.bucketsCount; i++)
		result.buckets[i] = biggerN.buckets[i];
	return result;
}

Bitset IntersectionOfSets(const Bitset& lhs, const Bitset& rhs)
{
	Bitset result(std::min(lhs.N, rhs.N));

	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
	for (int i = 0; i < minBucketsCount; i++)
		result.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	return result;
}