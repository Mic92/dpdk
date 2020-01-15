#include <rte_skb.h>
// implemented in lkl/drivers/net/dpdk/net.c
int (*rte_attach_skb)(struct rte_mbuf *rm);
