#可以有多个.cpp源文件
HHVM_EXTENSION(example example.cpp)
#只能有一个.php源文件
HHVM_SYSTEMLIB(example ext_example.php)