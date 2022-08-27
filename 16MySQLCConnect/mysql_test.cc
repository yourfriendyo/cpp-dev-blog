#include <iostream>
#include <cstdio>
#include <mysql/mysql.h>

std::string host   = "127.0.0.1";
std::string user   = "test";
std::string passwd = "TESTtest123456!";
std::string db     = "102_db";
int         port   = 3306;

int main()
{
    std::cout << "client_version: " << mysql_get_client_version() << std::endl;

    //0. 创建MYSQL句柄
    MYSQL* my = mysql_init(nullptr);

    //1. 连接MYSQL
    if (mysql_real_connect(my, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0) == nullptr) {
            std::cout << "connect failed" << std::endl;
            exit(1);
    }
    std::cout << "connect success" << std::endl;

    //2. 设置字符编码
    mysql_set_character_set(my, "utf8");

    //3. 执行SQL语句 
    
    // 增删改
    // std::string sql = "insert into account values (5, '猪八戒', 8.22)";
    // std::string sql = "delete from account where id=5";
    // std::string sql = "update account set name='唐僧' where id=5";

    // 查
    std::string sql = "select name from account";
    int code = mysql_query(my, sql.c_str());
    if (code != 0) {
        std::cout << "execute: " << sql << " failed" << std::endl;
        exit(2);
    }
    std::cout << "execute: " << sql << " success" << std::endl;
    // 获取执行结果
    MYSQL_RES* result = mysql_store_result(my);

    // 获取行数列数
    int rows = mysql_num_rows(result);
    int cols = mysql_num_fields(result);
    std::cout << "行数: " << rows << " 列数: " << cols << std::endl;

    // 获取字段名称
    MYSQL_FIELD* fields = mysql_fetch_fields(result);
    for (int i = 0; i < cols; i++) {
        std::cout << fields[i].name << "\t";
    }
    std::cout << std::endl;
    //遍历获取记录
    for (int i = 0; i < rows; i++) {
        MYSQL_ROW line = mysql_fetch_row(result);
        for (int j = 0; j < cols; j++) {
            std::cout << line[j] << "\t";
        }
        std::cout << std::endl;
    }
    

    free(result);
    //4. 关闭数据库
    mysql_close(my);


    return 0;
}
