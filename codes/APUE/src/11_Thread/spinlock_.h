/* APUE code examples .
 * :copyright: (c) 2016 by the huaxz1986@163.com.
 * :license: lgpl-3.0, see LICENSE for more details.
 */

/*
 *   第十一章：线程
 *
 * 测试 pthread_spinlock_t 相关函数的用法
 *
 */
#ifndef SPINLOCK_
#define SPINLOCK_
#include<pthread.h>
#ifdef __APPLE__
#include<os/lock.h>
#endif

#ifdef __linux__
/*!
 * \brief My_pthread_spin_init : 包装了 pthread_spin_init 函数
 * \param lock : 传递给 pthread_spin_init 函数的  lock 参数
 * \param pshared : 传递给 pthread_spin_init 函数的 pshared 参数
 * \return : 返回 pthread_spin_init 函数的值
 */
int My_pthread_spin_init(pthread_spinlock_t *lock,int pshared);
/*!
 * \brief My_pthread_spin_destroy : 包装了 pthread_spin_destroy 函数
 * \param lock : 传递给 pthread_spin_destroy 函数的 lock 参数
 * \return : 返回 pthread_spin_destroy 函数的值
 */
int My_pthread_spin_destroy(pthread_spinlock_t *lock);
/*!
 * \brief My_pthread_spin_lock : 包装了 pthread_spin_lock 函数
 * \param lock : 传递给 pthread_spin_lock 函数的 lock 参数
 * \return : 返回 pthread_spin_lock 函数的值
 */
int My_pthread_spin_lock(pthread_spinlock_t *lock);
/*!
 * \brief My_pthread_spin_trylock : 包装了 pthread_spin_trylock 函数
 * \param lock : 传递给 pthread_spin_trylock 函数的 lock 参数
 * \return : 返回 pthread_spin_trylock 函数的值
 */
int My_pthread_spin_trylock(pthread_spinlock_t *lock);
/*!
 * \brief My_pthread_spin_unlock : 包装了 pthread_spin_unlock 函数
 * \param lock : 传递给 pthread_spin_unlock 函数的 lock 参数
 * \return : 返回 pthread_spin_unlock 函数的值
 */
int My_pthread_spin_unlock(pthread_spinlock_t *lock);

/*!
 * \brief test_spinlock : 测试 pthread_spinlock_t 相关函数的用法
 */
void test_spinlock();
#endif /* __linux__ */

#ifdef __APPLE__
/*!
 * \brief My_macos_spin_init : macOS 自旋锁初始化
 * \param lock : 自旋锁指针
 * \return : 成功返回0
 */
int My_macos_spin_init(os_unfair_lock *lock);
/*!
 * \brief My_macos_spin_lock : macOS 自旋锁加锁
 * \param lock : 自旋锁指针
 * \return : 成功返回0
 */
int My_macos_spin_lock(os_unfair_lock *lock);
/*!
 * \brief My_macos_spin_unlock : macOS 自旋锁解锁
 * \param lock : 自旋锁指针
 * \return : 成功返回0
 */
int My_macos_spin_unlock(os_unfair_lock *lock);
/*!
 * \brief test_macos_spinlock : 测试 macOS 自旋锁
 */
void test_macos_spinlock();
#endif /* __APPLE__ */

#endif // SPINLOCK_

