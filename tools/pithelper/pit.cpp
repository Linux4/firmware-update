#include "pit.h"

#include <fstream>
#include <iostream>

struct PIT loadPIT(std::string file) {
    std::ifstream in(file);
    struct PIT pit;

    if (in.good()) {
        struct PITHeader header;

        in.read((char*) &header, PIT_HEADER_SIZE);

        if (header.magic != PIT_MAGIC) {
             std::cerr << "Invalid magic" << std::endl;
             return pit;
        }

        pit.header = header;

        for (uint32_t i = 0; i < header.entry_count; i++) {
            PITPartition part;

            in.read((char*) &part, PIT_PARTITION_SIZE);
            pit.partitions.push_back(part);
        }
    } else {
        std::cerr << "Failed to read PIT from " << file << std::endl;
    }

    return pit;
}
