wget https://github.com/google/googletest/archive/release-1.10.0.tar.gz
tar -zxvf ./release-1.10.0.tar.gz
cd googletest-release-1.10.0
mkdir build
cd build
cmake ..
make && make install
cd ../../
python3 googletest-release-1.10.0/googletest/scripts/fuse_gtest_files.py ./
