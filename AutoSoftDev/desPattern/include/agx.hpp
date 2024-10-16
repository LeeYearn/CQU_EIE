#ifndef AGX_HPP
#define AGX_HPP

#include <iostream>
#include <string>

using namespace std;

class AGX
{
private:
    string AGXid;
    string AI;
    string CUDAcore;
    string TensorCore;
    string RDD;
    string store;

public:
    AGX();
    void set();
    void print();

    void setAGXid(string AGXid);
    void setAI(string AI);
    void setCUDAcore(string CUDAcore);
    void setTensorCore(string TensorCore);
    void setRDD(string RDD);
    void setStore(string store);

    string getAGXid();
    string getAI();
    string getCUDAcore();
    string getTensorCore();
    string getRDD();
    string getStore();
};

#endif // AGX_HPP
