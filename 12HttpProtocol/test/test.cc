#include <iostream>
#include <string>
#include <jsoncpp/json/json.h>

// //请求协议
// struct request_t
// {
//     int x;       // 操作数1
//     int y;       // 操作数2
//     char op;     // 操作符 - "+-*/&"
// };
//
// //响应协议
// struct response_t
// {
//     int status;  // 状态码 status为0 表示计算正常，其他值表示异常退出
//     int result;  // 计算结果
// };
//
// int main()
// {
//     request_t req = { 10, 20, '+' };
//
//     Json::Value root; //可以承装任何对象
//     root["datax"] = req.x;
//     root["datay"] = req.y;
//     root["operator"] = req.op;
//
//     // Json::StyledWriter writer;
//     Json::FastWriter writer;
//     std::string json_string = writer.write(root);
//
//     std::cout << json_string << std::endl;
//
//     return 0;
// }

int main()
{
    // int a = 1;
    // std::string s = "abc";

    // Json::Value root; //承装对象
    // root["dataInt"] = a;
    // root["dataString"] = s;

    // // 两种序列化方式
    // Json::FastWriter fwriter;
    // std::string fast_string = fwriter.write(root);

    // Json::StyledWriter swriter;
    // std::string style_string = swriter.write(root);

    // std::cout << fast_string << std::endl;
    // std::cout << style_string << std::endl;

    // // 反序列化方式
    // std::string json_string = R"({"dataInt":1,"dataString":"abc"})"; //原始字符串

    // // Json::Value root;
    // Json::Reader reader;
    // reader.parse(json_string, root);

    // int data1 = root["dataInt"].asInt();
    // std::string data2 = root["dataString"].asCString();

    // std::cout << data1 << " " << data2 << std::endl;

    int data = 123;
    int key = 321;
    int a = data ^ key; //
    std::cout << a << std::endl;

}