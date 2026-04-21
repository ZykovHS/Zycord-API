#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stdint.h>
struct Packet {
    uint32_t type;
    uint32_t route_hash;
    uint32_t data_len;
    char data[1024];
};
#endif
