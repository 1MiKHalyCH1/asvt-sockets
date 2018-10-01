#include "arm_socket.h"

int arm_socket(int domain, int type, int protocol) 
{
	return syscall(281, domain, type, protocol);
}

int arm_connect(int fd, const struct arm_sockaddr *addr, int len) 
{
	return syscall(283, fd, addr, len);
}

ssize_t arm_send(int fd, const void *buf, size_t n, int flags)
{
	return syscall(289, fd, buf, n, flags);
}

ssize_t arm_recv(int fd, void *buf, size_t n, int flags)
{
	return syscall(291, fd, buf, n, flags);
}

int arm_setsockopt(int fd, int level, int optname, const void *optval, int optlen)
{
	return syscall(294, fd, level, optname, optval, optlen);
}

int arm_bind(int fd, struct arm_sockaddr *addr, int len)
{
	return syscall(282, fd, addr, len);
}

int arm_listen(int fd, int n)
{
	return syscall(284, fd, n);
}

int arm_accept(int fd, struct arm_sockaddr *addr, int *len)
{
	return syscall(285, fd, addr, len);
}