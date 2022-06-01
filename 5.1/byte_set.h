#ifndef BYTE_SET_H
#define BYTE_SET_H

union byte_set{
  int num;
  unsigned char bytes[4];
};

#endif