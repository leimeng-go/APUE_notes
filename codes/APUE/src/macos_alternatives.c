/* APUE macOS alternatives implementation */
#ifdef __APPLE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <os/lock.h>
#include <pthread.h>

// 1. macOS 自旋锁替代方案 (使用 os_unfair_lock 替代 pthread_spinlock_t)
int My_macos_spin_init(os_unfair_lock *lock) {
    *lock = OS_UNFAIR_LOCK_INIT;
    return 0;
}

int My_macos_spin_lock(os_unfair_lock *lock) {
    os_unfair_lock_lock(lock);
    return 0;
}

int My_macos_spin_unlock(os_unfair_lock *lock) {
    os_unfair_lock_unlock(lock);
    return 0;
}

void test_macos_spinlock() {
    printf("=== macOS Spinlock Test ===\n");
    os_unfair_lock lock;
    
    My_macos_spin_init(&lock);
    printf("Spinlock initialized\n");
    
    My_macos_spin_lock(&lock);
    printf("Spinlock acquired\n");
    
    My_macos_spin_unlock(&lock);
    printf("Spinlock released\n");
}

// 2. macOS 屏障替代方案 (使用 mutex + condition variable)
struct macos_barrier_t {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int current;
};

int My_macos_barrier_init(struct macos_barrier_t *barrier, int count) {
    barrier->count = count;
    barrier->current = 0;
    pthread_mutex_init(&barrier->mutex, NULL);
    pthread_cond_init(&barrier->cond, NULL);
    return 0;
}

int My_macos_barrier_destroy(struct macos_barrier_t *barrier) {
    pthread_mutex_destroy(&barrier->mutex);
    pthread_cond_destroy(&barrier->cond);
    return 0;
}

int My_macos_barrier_wait(struct macos_barrier_t *barrier) {
    pthread_mutex_lock(&barrier->mutex);
    
    barrier->current++;
    if (barrier->current == barrier->count) {
        // 最后一个线程，唤醒所有等待的线程
        barrier->current = 0;
        pthread_cond_broadcast(&barrier->cond);
        pthread_mutex_unlock(&barrier->mutex);
        return 1; // 返回1表示这是最后一个线程
    } else {
        // 等待其他线程
        pthread_cond_wait(&barrier->cond, &barrier->mutex);
        pthread_mutex_unlock(&barrier->mutex);
        return 0;
    }
}

void test_macos_barrier() {
    printf("=== macOS Barrier Test ===\n");
    struct macos_barrier_t barrier;
    
    My_macos_barrier_init(&barrier, 2);
    printf("Barrier initialized for 2 threads\n");
    
    // 这里只是示例，实际使用需要多线程
    printf("Thread would wait at barrier...\n");
    
    My_macos_barrier_destroy(&barrier);
    printf("Barrier destroyed\n");
}

// 3. macOS 用户认证替代方案 (使用 getpwnam 获取基本信息)
int My_macos_get_user_auth(const char* username) {
    printf("=== macOS User Auth Test ===\n");
    struct passwd *pwd = getpwnam(username);
    
    if (pwd != NULL) {
        printf("User: %s\n", pwd->pw_name);
        printf("UID: %d\n", pwd->pw_uid);
        printf("GID: %d\n", pwd->pw_gid);
        printf("Home: %s\n", pwd->pw_dir);
        printf("Shell: %s\n", pwd->pw_shell);
        
        // macOS 不直接提供密码hash访问，这是安全特性
        printf("Note: macOS doesn't expose password hashes for security\n");
        return 0;
    }
    return -1;
}

#endif /* __APPLE__ */ 