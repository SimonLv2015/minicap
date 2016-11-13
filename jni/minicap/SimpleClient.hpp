#ifndef MINICAP_SIMPLE_CLIENT_HPP
#define MINICAP_SIMPLE_CLIENT_HPP

class SimpleClient {
public:
  SimpleClient();
  ~SimpleClient();
  
  int
  conn(const char* ip, int port);

private:
  int mFd;
};

#endif
