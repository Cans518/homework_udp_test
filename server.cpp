#include <iostream>
#include <cstring>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>

#define s_Port 8443

int main() {
    // 创建 socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    // 设置服务器地址
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(s_Port);  // 设置服务器端口
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // 设置服务器IP地址

    // 发送数据
    const char* message = "XieyuHang 22124754 UDP";
    sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    std::cout << "\033[34;47mHand connected \033[0m\033[34;47mto \033[0m\033[33;47m127.0.0.1 \033[0m\033[34;47mport: \033[0m\033[33;47m" << s_Port << "\033[0m" << std::endl;

    std::string msg;
    while (1){
        std::cout << "\033[32mInput the message you want to send. (input 'q' to quit)\033[0m" << std::endl;
        std::getline(std::cin,msg);
        if (msg == ""){
            std::cout << "\033[31mPlease input something\033[0m" << std::endl;
            continue;
        }
        sendto(sockfd, (msg.c_str()), strlen(msg.c_str()), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        if (msg == "q")
            break;
        std::cout << "\033[36mHad send \033[0m\033[33;47m" << msg << "\033[0m \033[36mto \033[0m\033[33m127.0.0.1\033[0m \033[36mport:\033[0m \033[33m" << s_Port << "\033[0m" << std::endl;
    }

    // 关闭 socket
    close(sockfd);

    return 0;
}