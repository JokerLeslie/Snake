/*************************************************************************
	> File Name: log.h
	> Author: knockinn
	> Mail: czhang_cqu@163.com
	> Created Time: 2021年12月20日 星期一 11时38分36秒
 ************************************************************************/

#ifndef _LOG_H
#define _LOG_H

#include <cstdio>

#define LOG_DEBUG(fmt, ...) printf("<%s : %u>: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__) 
#define LOG_ERROR(fmt, ...) printf("<%s : %u>: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__) 


#endif
