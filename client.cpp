#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <json/json.h>

#define s_Port 8443

int main() {
    // 创建 socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    // 设置本地地址
    sockaddr_in localAddr;
    memset(&localAddr, 0, sizeof(localAddr)); // 清空地址结构体
    localAddr.sin_family = AF_INET;// 设置为IPV4
    localAddr.sin_port = htons(s_Port);  // 设置端口
    localAddr.sin_addr.s_addr = INADDR_ANY;  // 任意本地地址

    // 绑定 socket
    bind(sockfd, (struct sockaddr*)&localAddr, sizeof(localAddr));

    std::cout << "\033[34;47m Now listening \033[0m\033[33;47m127.0.0.1 \033[0m\033[34;47m, port: \033[0m\033[33;47m" << s_Port << " \033[0m \n" << std::endl;

    // 接收数据
    char buffer[1024]; // 接收缓冲区
    memset(buffer, 0, sizeof(buffer));
    sockaddr_in clientAddr; // 客户端地址
    socklen_t clientAddrLen = sizeof(clientAddr);

    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
    // 打印接收到的数据
    std::cout << "\033[32m" << buffer << "\033[0m\n" << "\033[32mNow conneted!\033[0m \n";
    memset(buffer, 0, sizeof(buffer));

    int n = 1;

    while (1){
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        // 打印接收到的数据
        if (buffer[0] == 'q' && buffer[2] == 0){
            std::cout << "\n\033[34;47m End of Listening, now go to quit! \033[0m\n" << std::endl;
            break;
        }
        std::cout << "\033[36mReceived message \033[0m\033[31m" << n++ << "\033[0m\033[31m:\033[0m \033[35;47m " << buffer << " \033[0m" << std::endl;
        memset(buffer, 0, sizeof(buffer));
    }
    
    close(sockfd);

    return 0;
}
