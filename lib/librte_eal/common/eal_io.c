#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>
#include <errno.h>

int loop_write(int fd, const void *buf, size_t nbytes) {
	const uint8_t *p = buf;

	assert(fd >= 0);
	assert(buf);

	if (nbytes > (size_t)SSIZE_MAX)
		return -EINVAL;

	do {
		ssize_t k;

		k = write(fd, p, nbytes);
		if (k < 0) {
			if (errno == EINTR)
				continue;

			return -errno;
		}

		if (nbytes > 0 && k == 0) /* Can't really happen */
			return -EIO;

		assert((size_t)k <= nbytes);

		p += k;
		nbytes -= k;
	} while (nbytes > 0);

	return 0;
}
