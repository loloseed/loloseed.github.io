/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "hphp/runtime/ext/extension.h"

namespace HPHP {

/**
 * 用c++实现的example_sum函数
 */
static int64_t HHVM_FUNCTION(example_sum, int64_t a, int64_t b) {
  return a + b;
}

// 对外暴露常量
const StaticString s_EXAMPLE1_YEAR("EXAMPLE1_YEAR");

static class ExampleExtension : public Extension {
 public:
  ExampleExtension() : Extension("example") {}
  // 在moduleInit函数注册对php输出的函数、变量
  virtual void moduleInit() {
    // 注册函数
    HHVM_FE(example_sum);
    // 注册全局变量
    Native::registerConstant<KindOfInt64>(s_EXAMPLE1_YEAR.get(), 2019);
    loadSystemlib();
  }
} s_example_extension;

HHVM_GET_MODULE(example)

} // namespace HPHP