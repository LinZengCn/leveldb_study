cd ./build
cmake --build .
cp libleveldb.a ../test
cd ../test
g++ -g ldbtest.cpp -o ldbtest libleveldb.a  -I../include -lpthread

