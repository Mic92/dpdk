#include "rte_hash_crc.h"

uint8_t crc32_alg = CRC32_SW;

/* Setting the best available algorithm */
RTE_INIT(rte_hash_crc_init_alg)
{
	rte_hash_crc_set_alg(CRC32_SSE42_x64);
}
