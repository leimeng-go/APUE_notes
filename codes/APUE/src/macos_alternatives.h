#ifndef MACOS_ALTERNATIVES_H
#define MACOS_ALTERNATIVES_H

#ifdef __APPLE__
#include <os/lock.h>
#include <pthread.h>

// macOS 自旋锁替代方案
int My_macos_spin_init(os_unfair_lock *lock);
int My_macos_spin_lock(os_unfair_lock *lock);
int My_macos_spin_unlock(os_unfair_lock *lock);
void test_macos_spinlock(void);

// macOS 屏障替代方案 (前向声明)
typedef struct macos_barrier_t macos_barrier_t;

int My_macos_barrier_init(struct macos_barrier_t *barrier, int count);
int My_macos_barrier_destroy(struct macos_barrier_t *barrier);
int My_macos_barrier_wait(struct macos_barrier_t *barrier);
void test_macos_barrier(void);

// macOS 用户认证替代方案
int My_macos_get_user_auth(const char* username);

#endif /* __APPLE__ */

#endif /* MACOS_ALTERNATIVES_H */ 