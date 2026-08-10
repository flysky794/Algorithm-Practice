# 编译器
CXX := g++

# 编译选项：开启调试信息、警告、C++11标准
CXXFLAGS := -g -Wall -std=c++11

# 链接选项，按需添加库（如 -lm 数学库）
LDFLAGS :=

# 自动扫描当前目录所有 .cpp 文件
SRCS := $(wildcard *.cpp)
# 每个 .cpp 对应一个同名可执行文件（去掉.cpp后缀）
TARGETS := $(patsubst %.cpp, %, $(SRCS))

# 默认目标：编译所有 cpp 文件，生成全部可执行程序
all: $(TARGETS)

# 模式规则：将 xxx.cpp 编译为同名可执行文件 xxx
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

# 清理：删除所有可执行文件和 .o 中间文件
clean:
	rm -f $(TARGETS) *.o

.PHONY: all clean
