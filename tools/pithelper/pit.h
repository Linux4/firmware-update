#ifndef _PIT_H
#define _PIT_H

#include <inttypes.h>
#include <map>
#include <string>
#include <vector>

#define PIT_HEADER_SIZE 28
#define PIT_PARTITION_SIZE 132

#define PIT_MAGIC 305436790

struct PITHeader {
    uint32_t magic;
    uint32_t entry_count;
    char port[4];
    char format[4];
    char chip[4];
    char unknown[4];
};

struct PITPartition {
    uint32_t binary_type;
    uint32_t device_type;
    uint32_t identifier;
    char attributes[4];
    char update_attributes[4];
    uint32_t block_size_or_offset;
    uint32_t block_count;
    uint32_t file_offset;
    uint32_t file_size;
    char partition_name[32];
    char flash_filename[32];
    char fota_filename[32];
};

struct PIT {
    struct PITHeader header;
    std::vector<PITPartition> partitions;
};

struct PIT loadPIT(std::string file);

#endif /* !_PIT_H */
