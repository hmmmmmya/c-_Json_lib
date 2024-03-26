#目标文件名
TARGET = json_parser

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic -O3

deps = $(shell find . -name "*.h")

# 依赖关系用冒号(:)隔开，左边的叫做目标(target);
# 右边称为依赖(prerequisites)
SRC_DIR := .

# 构建目录
BUILD_DIR := ./build

# 目标文件
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS += $(addprefix $(BUILD_DIR)/,$(patsubst %.cpp,%.o, $(notdir $(wildcard $(SRC_DIR)/*.cpp))))

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)

# 这时候因为目标文件已经脱离了源文件的环境，
# 用makefile隐含规则自动编译已经不可行了。
# 我们显式执行编译命令
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(deps)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean   # 伪目标的意义就是，无论如何都执行下面的命令
clean:
	rm -f $(TARGET) $(OBJS)
