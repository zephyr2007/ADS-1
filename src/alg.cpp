// Copyright 2022 NNTU-CS
#include <vector>
#include <cstdint>
#include "alg.h"
bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    if (value == 2 || value == 3) {
        return true;
    }
    if (value % 2 == 0 || value % 3 == 0) {
        return false;
    }
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool isPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n < 1) {
        return 0;
    }
    uint64_t count = 0;
    uint64_t current = 1;
    while (count < n) {
        current++;
        if (isPrime(current)) {
            count++;
        }
    }
    return current;
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (!isPrime(value)) {
        value++;
    }
    return value;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    std::vector<uint64_t> primes;
    for (uint64_t i = lbound; i < hbound; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    for (size_t i = 0; i < primes.size(); ++i) {
        if (i + 1 < primes.size() && primes[i + 1] - primes[i] == 2) {
            count++;
        }
    }
    return count;
}
