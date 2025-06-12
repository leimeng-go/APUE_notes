/* APUE code examples .
 * :copyright: (c) 2016 by the huaxz1986@163.com.
 * :license: lgpl-3.0, see LICENSE for more details.
 */

/*
 *   第十一章：线程
 *
 * 测试 pthread_barrier_t 相关函数的用法
 *
 */
#ifndef BARRIER_
#define BARRIER_
#include<pthread.h>

#ifdef __linux__
/*!
 * \brief My_pthread_barrier_init : 包装了 pthread_barrier_init 函数
 * \param barrier : 传递给 pthread_barrier_init 函数的 barrier 参数
 * \param attr : 传递给 pthread_barrier_init 函数的 attr 参数
 * \param count : 传递给 pthread_barrier_init 函数的 count 参数
 * \return : 返回 pthread_barrier_init 函数的值
 */
int My_pthread_barrier_init(pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, int count);
/*!
 * \brief My_pthread_barrier_destroy : 包装了 pthread_barrier_destroy 函数
 * \param barrier : 传递给 pthread_barrier_destroy 函数的 barrier 参数
 * \return : 返回 pthread_barrier_destroy 函数的值
 */
int My_pthread_barrier_destroy(pthread_barrier_t *barrier);
/*!
 * \brief My_pthread_barrier_wait : 包装了 pthread_barrier_wait 函数
 * \param barrier : 传递给 pthread_barrier_wait 函数的 barrier 参数
 * \return : 返回 pthread_barrier_wait 函数的值
 */
int My_pthread_barrier_wait(pthread_barrier_t * barrier);

/*!
 * \brief test_barrier : 测试 pthread_barrier_t 相关函数的用法
 */
void test_barrier();
#endif /* __linux__ */

#ifdef __APPLE__
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int current;
} macos_barrier_t;

/*!
 * \brief My_macos_barrier_init : macOS 屏障初始化
 * \param barrier : 屏障指针
 * \param count : 等待的线程数量
 * \return : 成功返回0
 */
int My_macos_barrier_init(macos_barrier_t *barrier, int count);
/*!
 * \brief My_macos_barrier_destroy : macOS 屏障销毁
 * \param barrier : 屏障指针
 * \return : 成功返回0
 */
int My_macos_barrier_destroy(macos_barrier_t *barrier);
/*!
 * \brief My_macos_barrier_wait : macOS 屏障等待
 * \param barrier : 屏障指针
 * \return : 成功返回0
 */
int My_macos_barrier_wait(macos_barrier_t *barrier);
/*!
 * \brief test_macos_barrier : 测试 macOS 屏障
 */
void test_macos_barrier();
#endif /* __APPLE__ */

#endif // BARRIER_

