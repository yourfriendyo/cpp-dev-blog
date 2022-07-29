#pragma once
#include <iostream>

//请求协议
struct request_t
{
    int x;       // 操作数1
    int y;       // 操作数2
    char op;     // 操作符 - "+-*/&"
};

//响应协议
struct response_t
{
    int status;  // 状态码 status为0 表示计算正常，其他值表示异常退出
    int result;  // 计算结果
};