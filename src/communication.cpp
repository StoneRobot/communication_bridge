#include <communication_bridge/communication.h>

bool Communication::checkNet(std::string URL)
{
    /*
       -c 2（代表ping次数，ping 2次后结束ping操作） -w 2（代表超时时间，2秒后结束ping操作） 
    */ 
    system("ping %s -c 2 -w 2 >netlog.bat", URL.c_str()); 
    sleep(2);
 
    //把文件一行一行读取放入vector
    ifstream infile;
    infile.open("netlog.bat"); 
    string s;
    vector<string> v;
    while(infile)
    {
        getline(infile,s);
        if(infile.fail()) 
            break;
        v.push_back(s);
    }
    infile.close();
 
    //读取倒数第二行 2 packets transmitted, 2 received, 0% packet loss, time 1001ms
    if (v.size() > 1)
    {
        string data = v[v.size()-2];    
        int iPos = data.find("received,");  
        if (iPos != -1 )
        {
            data = data.substr(iPos+10,3);//截取字符串返回packet loss
            int  n = atoi(data.c_str()); 
            if(n == 0)
             return 1; 
            else
            return 0 ; 
        }
       
    }else
    {
        return 0;
    }
}

bool Communication::checkAllNect()
{
    std::vector<std::string> url = {"10.10.56.214"};
    for(int i=0; i<url.size(); ++i)
    if (checkNet(url[i]))
    { 
        printf("%s: 网络连接成功\n", url[i].c_str()); 
    }
    else    
    { 
        printf("%s: 网络连接失败\n", url[i].c_str());
    }
}

bool Communication::stopCommand()
{
    system("rosservice call /UR51/set_robot_enable 'enable: false'");
    system("rosservice call /UR52/set_robot_enable 'enable: false'");
    system("rosservice call /UR51/clear_robot_fault '{}'");
    system("rosservice call /UR52/clear_robot_fault '{}'");
}