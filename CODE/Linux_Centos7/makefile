XX = g++
CXXFLAGS = -g -std=c++11

# 2. 自动获取当前目录下的所有 .cpp 源文件
SRCS = $(wildcard *.cpp)

# 3. 核心一步：把 .cpp 后缀去掉，得到对应的可执行文件列表
# 例如：myprocess.cpp main.cpp 变成 myprocess main
TARGETS = $(SRCS:.cpp=)

# 4. 默认目标：make 默认编译所有源文件生成对应的可执行文件
all: $(TARGETS)

# 5. 模式规则：定义如何从 .cpp 生成同名（不带后缀）的可执行文件
# $< 代表依赖的源文件（如 myprocess.cpp）
# $@ 代表生成的目标文件（如 myprocess）
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 6. 清理规则：自动清理所有生成的可执行文件以及 .o 中间文件
clean:
	rm -f $(TARGETS)
	rm -f *.o
