#pragma once
#include <iostream>

namespace CPTask
{
    class Task
    {
    private:
        int _x;
        int _y;
        char _op; // + - * / &   
        int _res;
        int Run() {
            switch (_op) {
            case '+':
                _res = _x + _y;
                break;
            case '-':
                _res = _x - _y;
                break;
            case '*':
                _res = _x * _y;
                break;
            case '/':
                _res = _x / _y;
                break;
            case '&':
                _res = _x & _y;
                break;
            default:
                std::cout << "unknow fatal!" << std::endl;
                break;
            }
            return _res;
        }
    public:
        Task()
        {}
        Task(int x, int y, char op) : _x(x), _y(y), _op(op), _res(0)
        {}

        int operator()() {
            return Run();
        }

        void PrintTask() {
            printf("%2d %c %2d = %2d\n", _x, _op, _y, _res);
        }
        ~Task()
        {}

    };

}