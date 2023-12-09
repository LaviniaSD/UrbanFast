# Use a base image with gcc installed, for example
FROM ubuntu:latest

# Install the necessary dependencies
RUN apt-get update && \
    apt-get install -y \
    g++ \
    cmake \
    make \
    libgtest-dev \
    git

# Clone the Google Test repository and install it
RUN git clone https://github.com/google/googletest.git /googletest && \
    cd /googletest && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install

# Set the working directory in the container
WORKDIR /usr/src/myapp

# Copy your source code into the Docker image
COPY . .
ADD . .

# Compile your test
RUN g++ -std=c++14 -o my_test \
    Tests.cpp \ 
    Map.cpp \
    Order.cpp \
    DeliveryMan.cpp \
    EdgeNode.cpp \
    Heap.cpp \
    Seller.cpp \
    Warehouse.cpp \
    -lgtest -lgtest_main -pthread

# Command to run when the container starts
CMD ["./my_test"]
