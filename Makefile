TARGET=similarity
CXX=g++
CXXFLAGS= -O2 -Wall -std=c++17
BUILD_DIR=build
RES_DIR=result
SRC_DIR=src
SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(subst $(SRC_DIR),$(BUILD_DIR),$(SRCS:.cpp=.o))
	CVINC=`pkg-config --cflags opencv`
	CVLIB=`pkg-config --libs opencv`

all: $(BUILD_DIR) $(RES_DIR) $(TARGET)

$(BUILD_DIR):
		mkdir $(BUILD_DIR)

$(RES_DIR):
		mkdir $(RES_DIR)

$(TARGET): $(OBJS)
		$(CXX) $(CXXFLAGS) $^ ${CVINC} ${CVLIB} -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c $^ ${CVINC} ${CVLIB} -o $@

clean:
		rm -rf $(BUILD_DIR) $(TARGET)
