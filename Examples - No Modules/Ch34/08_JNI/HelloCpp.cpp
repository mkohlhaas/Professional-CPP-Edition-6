#include "HelloCpp.h"
#include <iostream>
#include <jni.h>

JNIEXPORT void JNICALL
Java_HelloCpp_callCpp (JNIEnv *, jclass)
{
  std::cout << "Hello from C++!" << std::endl;
}
