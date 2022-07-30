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


//序列化请求
std::string SerializeRequest(const request_t& req)
{
    Json::Value root;
    root["datax"] = req.x;
    root["datay"] = req.y;
    root["operator"] =req.op;
    Json::FastWriter writer;
    return writer.write(root);
}

// 反序列化请求
void DeserializeRequest(const std::string json_string, request_t& req)
{
    Json::Value root;
    Json::Reader reader;
    reader.parse(json_string, root);
    req.x = root["datax"].asInt();
    req.y = root["datay"].asInt();
    req.op = (char)root["operator"].asInt();
}


//序列化响应
std::string SerializeResponse(const response_t& resp)
{
    Json::Value root;
    root["status"] = resp.status;
    root["result"] = resp.result;
    Json::FastWriter writer;
    return writer.write(root);
}

//反序列化响应
void DeserializeResponse(const std::string json_string, response_t& resp)
{
    Json::Value root;
    Json::Reader reader;
    reader.parse(json_string, root);
    resp.status = root["status"].asInt();
    resp.result = root["result"].asInt();
}