#include <map>
#include <atomic>
#include "../include/protocol.h"
struct Bucket {
    std::atomic<int> tokens{5};
};
std::map<uint32_t, Bucket*> limits;
bool acquire_token(uint32_t hash) {
    if (limits.find(hash) == limits.end()) {
        limits[hash] = new Bucket();
    }
    int current = limits[hash]->tokens.load();
    while (current > 0) {
        if (limits[hash]->tokens.compare_exchange_weak(current, current - 1)) {
            return true;
        }
    }
    return false;
}
