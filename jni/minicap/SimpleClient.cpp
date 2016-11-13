#include "SimpleClient.hpp"
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include<arpa/inet.h> //inet_addr

SimpleClient::SimpleClient(): mFd(0) {
}

SimpleClient::~SimpleClient() {
  if (mFd > 0) {
    ::close(mFd);
  }
}

int
SimpleClient::conn(const char* ip, int port) {
  int sfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sfd < 0) {
    return sfd;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);
  
  if( connect(sfd,(struct sockaddr *)&addr, sizeof(addr)) < 0){
    ::close(sfd);
    return -1;
  }

  ::listen(sfd, 1);
  mFd = sfd;

  return mFd;
}
