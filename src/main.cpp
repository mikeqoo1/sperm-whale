#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#include "animal.h"
#include "sea.h"
mutex m; //例項化m物件,不要理解為定義變數
void Setting(Animal *a)
{
    string name = "抹香鯨";
    string area = "大海";
    int age = 100;
    int weight = 50000;
    int high = 20;
    a->SetAnimal(name, area, age, weight, high);
}

void test_thread_func1(int arg)
{
    cout << "我是子執行緒(a_thread), 傳入引數為" << arg << endl;
    cout << "a_thread子執行緒id為" << this_thread::get_id() << endl;
    lock_guard<mutex> g1(m); //用此語句替換了m.lock()；lock_guard傳入一個引數時,該引數為互斥量,此時呼叫了lock_guard的建構函式,申請鎖定m
    cout << "test_thread_func1函式正在改寫變數" << endl;
    cout << "原始變數為" << arg << endl;
    cout << "現在變數為" << arg + 2 << endl;
} //此時不需要寫m.unlock(),g1出了作用域被釋放,自動呼叫解構函式,於是m被解鎖

void test_thread_func2(int arg)
{
    cout << "我是子執行緒(b_thread), 傳入引數為" << arg << endl;
    cout << "b_thread子執行緒id為" << this_thread::get_id() << endl;
    lock_guard<mutex> g2(m);
    cout << "test_thread_func2函式正在改寫變數" << endl;
    cout << "原始變數為" << arg << endl;
    cout << "現在變數為" << arg + 1 << endl;
}

int main()
{

    cout << "         \\/        " << endl;
    cout << "          **********" << endl;
    cout << "          *    ^^  *" << endl;
    cout << "          *        *" << endl;
    cout << "          *****    *" << endl;
    cout << "              *    *" << endl;
    cout << "            v-*     *" << endl;
    cout << "            v-*      *" << endl;
    cout << "              *       *" << endl;
    cout << "              *        *" << endl;
    cout << "              *         *" << endl;
    cout << "              *          *" << endl;
    cout << "              *************" << endl;
    cout << "                __|  __|   " << endl;

    // std::tuple範例
    string name, area;
    int age, weight, high;
    Animal a;
    std::tie(std::ignore, std::ignore, std::ignore, std::ignore, std::ignore) = a.GetAnimal();
    a.Print();

    a.SetAnimal("大白鯊", "大海", 10, 2000, 5);
    name = std::get<0>(a.GetAnimal());
    area = std::get<1>(a.GetAnimal());
    age = std::get<2>(a.GetAnimal());
    weight = std::get<3>(a.GetAnimal());
    high = std::get<4>(a.GetAnimal());
    a.Print();

    Setting(&a);
    std::tie(name, area, age, weight, high) = a.GetAnimal();
    a.Print();

    // std::map範例
    //新增用insert指令
    a.InsertMap(name, a);

    //新增用array的方式
    // noahs_ark["虎鯨"] = b;
    a.SetAnimal("虎鯨", "大海", 10, 6000, 8);
    a.InsertMap("虎鯨", a);
    a.SetAnimal("大白鯊", "大海", 10, 2000, 5);
    a.InsertMap("大白鯊", a);

    // map的遍尋和搜尋
    a.PrintMap();
    a.FindMap("海豚");

    //子類別的範例
    Sea godzilla;
    godzilla.SetAnimal("哥吉拉", "地心", 0, 96340, 119.8);
    godzilla.SetSea("怪獸之王", "核能背鰭", 99999);
    godzilla.Print(); //多載

    Sea kong;
    kong.SetAnimal("金剛", "骷髏島", 0, 0, 102);
    kong.SetSea("巨獸種族", "無", 88888);
    kong.Print(); //多載

    //運算子多載
    Sea tempaaa;
    string godzilla_name, kong_name;
    godzilla_name = std::get<0>(godzilla.GetAnimal());
    kong_name = std::get<0>(kong.GetAnimal());
    godzilla.GetAnimal();
    tempaaa = godzilla + kong;
    std::cout << "Power合併=" << tempaaa.GetPower() << std::endl;
    std::cout << "Name=" << godzilla_name << std::endl;
    std::cout << "Name=" << kong_name << std::endl;

    if (godzilla > kong)
    {
        cout << "哥吉拉比金剛厲害" << endl;
    }

    //多執行緒 C++
    cout << "----------C++ 多執行緒的範例----------" << endl;
    int wqsaxz = 0;
    std::thread a_thread(test_thread_func1, wqsaxz);
    cout << "主執行緒中顯示子執行緒id(a_thread)為" << a_thread.get_id() << endl;
    std::thread b_thread(test_thread_func2, wqsaxz);
    cout << "主執行緒中顯示子執行緒id(b_thread)為" << b_thread.get_id() << endl;
    a_thread.join();
    b_thread.join();

    //閒來無聊畫個圖
    cout << "閒來無聊畫個圖" << endl;
    int i, j, k, m, n;
    for (i = 1; i <= 5; i++)
    {
        // printf("%d", i);

        for (j = 5; j > i; j--)
        {
            cout << " ";
        }
        for (k = 1; k <= i; k++)
        {
            cout << "*";
        }
        for (m = 2; m <= i; m++)
        {
            cout << "*";
        }
        for (n = 5; n > i; n--)
        {
            cout << " ";
        }
        cout << endl;
    }

    // timeval 系統時間轉換秒
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("%ld    %ld\n", tv.tv_usec, tv.tv_sec);

    // time_t
    time_t now = time(0);
    cout << "Number of sec since January 1,1970:" << now << endl;
    tm *ltm = localtime(&now);
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;

    //安全術語
    /*
    EXP     Exploit          指可利用的點 (漏洞 程式碼之類的)
    PoC     Proof of Concept 漏洞的概念證明 常見是一段可重複出現漏洞的程式碼
    payload                  泛指漏洞利用成功後所要做的事情（如Cracker會做一些有害的或者惡性的行為
    shellcode                payload的一種 讓攻擊者獲得 shell（建立正向/反向shell而得名
    想象自己是一個特務, 你的目的是監控一個人, 有一天你懷疑目標家的窗戶可能没有關, 於是你上前推了推, 结果推開了, 這是一個 PoC
    於是你回去了, 開始準備第二天的滲透計畫, 第二天你通過同樣的漏洞渗透進去了他家, 仔细查看了所有的重要文件, 離開時安裝了一個隱蔽的竊聽器
    這一天你所做的就是一個 Exp, 你在他家所做的行為就是不同的 Payload, 就把竊聽器當作 Shellcode 吧
    */

    //檢查機器上開啟的Port並列出連線IP
    cout << "檢查機器上開啟的Port並列出連線IP" << endl;
    struct sockaddr_in client;
    int sock;

    client.sin_family = AF_INET;
    int port = 3306;
    client.sin_port = htons(port);
    client.sin_addr.s_addr = inet_addr("192.168.199.236");
    // client.sin_addr.s_addr = htonl(INADDR_ANY); //指定地址0.0.0.0 這個IP實際上表示不確定地址, 或"所有IP" "任意IP"
    sock = (int)socket(AF_INET, SOCK_STREAM, 0);

    int result = connect(sock, (struct sockaddr *)&client, sizeof(client));

    if (result == 0)
    {
        cout << "該" << port << "有開啟" << endl;
        // stringstream cmd;
        // cmd.str("");
        // cmd.clear();
        // cmd << "netstat -plan|grep :3306|awk {'print $5'}|cut -d: -f 1|sort|uniq -c|sort -nk 1";
        string cmd = "netstat -plan|grep :3306|awk {'print $5'}|cut -d: -f 1|sort|uniq -c|sort -nk 1";
        system(cmd.c_str());
    }
    else
    {
        cout << "該" << port << "沒有開啟" << endl;
    }
}
