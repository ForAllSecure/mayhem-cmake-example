FROM ubuntu AS builder

# Install required packages
RUN apt-get update && \
    apt-get install -y build-essential cmake libgtest-dev clang

COPY . /workspace
WORKDIR /workspace

# Run CMake to build all targets
RUN CC=clang CXX=clang++ cmake -S . -B build -DBUILD_TESTS=ON -DBUILD_FUZZ=ON && \
    cmake --build build

FROM ubuntu
COPY --from=builder /workspace/build/* /
