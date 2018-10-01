#ifndef arm_socket_h__
#define arm_socket_h__

#include <sys/syscall.h>
#include <sys/types.h>

// constannts
#define ARM_SOCK_STREAM     1
#define ARM_AF_INET         2
#define ARM_SOL_SOCKET      1
#define ARM_SO_REUSEADDR    2

// structs
struct arm_in_addr {
    unsigned long       s_addr;
};

struct arm_sockaddr {
    unsigned short      sa_family;
    char                sa_data[14];
};

struct arm_sockaddr_in {
    short               sin_family;
    unsigned short      sin_port;
    struct arm_in_addr  sin_addr;
    char                sin_zero[8];
};

// functions
int arm_socket(int domain, int type, int protocol);
int arm_connect(int fd, const struct arm_sockaddr *addr, int len);
ssize_t arm_send(int fd, const void *buf, size_t n, int flags);
ssize_t arm_recv(int fd, void *buf, size_t n, int flags);
int arm_setsockopt(int fd, int level, int optname, const void *optval, int optlen);
int arm_bind(int fd, struct arm_sockaddr *addr, int len);
int arm_listen(int fd, int n);
int arm_accept(int fd, struct arm_sockaddr *addr, int *len);

#endif  // arm_socket_h__