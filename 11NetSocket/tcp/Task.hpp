#pragma once
#include <iostream>

namespace NSTask
{
    static std::unordered_map<std::string, std::string> g_dist;
    class Task
    {
    private:
        int _sock;
        int Run()
        {
            while (true) {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                ssize_t s = recv(_sock, buffer, sizeof(buffer), 0);

                if (s > 0) {
                    buffer[s] = 0;

                    // FILE* fp = popen(buffer, "r"); // buffer内容看作命令
                    //
                    // std::string res;
                    // while (fgets(buffer, sizeof(buffer), fp) != NULL) { // 将命令结果提取到buffer中
                    //     res += buffer;
                    // }
                    //
                    // pclose(fp);

                    std::string res;
                    Translate(std::string(buffer), &res); //英译汉程序

                    std::string reply = ">>>server<<< \n" + res;
                    send(_sock, reply.c_str(), reply.size(), 0);
                }
                else if (s == 0) {
                    std::cout << "client quit..." << std::endl;
                    break;
                }
                else {
                    std::cerr << "recv error" << std::endl;
                    break;
                }
            }
            close(_sock); // 释放套接字
        }
    public:
        Task() : _sock(-1)
        {
            InitDist(); // 初始化字典
        }
        Task(int sock) : _sock(sock)
        {}
        ~Task()
        {}

        void InitDist()
        {
            if (g_dist.empty()) {
                g_dist.insert(std::make_pair("hello", "你好"));
                g_dist.insert(std::make_pair("world", "世界"));
                g_dist.insert(std::make_pair("socket", "套接字"));
                g_dist.insert(std::make_pair("tree", "树"));
                g_dist.insert(std::make_pair("image", "图片"));
            }
        }

        void Translate(const std::string& req, std::string* resp)
        {
            auto it = g_dist.find(req);

            if (it == g_dist.end()) {
                *resp = "?";
                return;
            }
            *resp = it->second;
        }

        int operator()() {
            return Run();
        }
    };
}