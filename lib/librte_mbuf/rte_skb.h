#include <rte_mbuf.h>
// implemented in lkl/drivers/net/dpdk/net.c
extern int (*rte_attach_skb)(struct rte_mbuf *rm);
