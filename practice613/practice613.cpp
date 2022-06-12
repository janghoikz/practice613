#include <iostream>

//참조

struct Statinfo
{
    int hp;
    int attack;
    int defence;
};

//[매개변수][RET][지역변수(info)][매개변수(info(100.8.5))][RET][지역변수]
void CreateMonster(Statinfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;
}

void CreateMonster(Statinfo info)
{
    info.hp = 100;
    info.attack = 8;
    info.defence = 5;
}

//값을 수정하지 않는다면, 양쪽다 문제 없음

// 1) 값 전달 방식

void PrintInfoByCopy(Statinfo info)
{
    std::cout << "HP: " << info.hp << std::endl;
    std::cout << "ATTACK: " << info.attack << std::endl;
    std::cout << "DEFENSE: " << info.defence << std::endl;
}

// 2)주소전달방식
void PrintInfoByPtr(Statinfo* info)
{
    std::cout << "HP: " << info->hp << std::endl;
    std::cout << "ATTACK: " << info->attack << std::endl;
    std::cout << "DEFENSE: " << info->defence << std::endl;
}

void PrintInfoByRef(Statinfo& info)
{
    std::cout << "HP: " << info.hp << std::endl;
    std::cout << "ATTACK: " << info.attack << std::endl;
    std::cout << "DEFENSE: " << info.defence << std::endl;
}

//값전달 StatInfo로 넘기면 원본크기만큼 복사
//주소전달 StatInfo*로 넘기면 8바이트
//참조전달 StatInfo&로 넘기면 8바이트
//참조전달은 값전달처럼 편하게 사용하고 주소전달처럼 주소를 이용해 진퉁을 건드리는 방식

int main()
{
    int number = 1;

    Statinfo info;
    CreateMonster(&info);

    PrintInfoByCopy(info);
    PrintInfoByPtr(&info);
    PrintInfoByRef(info);

    return 0;
}
