#include "../include/agx.hpp"

AGX::AGX()
{
    this->AGXid = "AGX Xavier";
    this->AI = "32 TOPS";
    this->CUDAcore = "512";
    this->TensorCore = "64";
    this->RDD = "32";
    this->store = "32";
}

void AGX::set()
{
    cout << "设置AGX套件型号: " << endl;
    cin >> this->AGXid;
    cout << "设置AI算力: " << endl;
    cin >> this->AI;
    cout << "设置CUDA核心数: " << endl;
    cin >> this->CUDAcore;
    cout << "设置TensorCore数: " << endl;
    cin >> this->TensorCore;
    cout << "设置显存容量: " << endl;
    cin >> this->RDD;
    cout << "设置存储容量: " << endl;
    cin >> this->store;
}

void AGX::print()
{
    cout << "\033[1mAGX套件型号: \033[0m" << this->AGXid << endl;
    cout << "\033[1mAI算力: \033[0m" << this->AI << endl;
    cout << "\033[1mCUDA核心数: \033[0m" << this->CUDAcore << endl;
    cout << "\033[1mTensorCore数: \033[0m" << this->TensorCore << endl;
    cout << "\033[1m显存容量: \033[0m" << this->RDD << " GB" << endl;
    cout << "\033[1m存储容量: \033[0m" << this->store << " GB" << endl;
}

// Setter and Getter implementations
void AGX::setAGXid(string AGXid) { this->AGXid = AGXid; }
void AGX::setAI(string AI) { this->AI = AI; }
void AGX::setCUDAcore(string CUDAcore) { this->CUDAcore = CUDAcore; }
void AGX::setTensorCore(string TensorCore) { this->TensorCore = TensorCore; }
void AGX::setRDD(string RDD) { this->RDD = RDD; }
void AGX::setStore(string store) { this->store = store; }

string AGX::getAGXid() { return this->AGXid; }
string AGX::getAI() { return this->AI; }
string AGX::getCUDAcore() { return this->CUDAcore; }
string AGX::getTensorCore() { return this->TensorCore; }
string AGX::getRDD() { return this->RDD; }
string AGX::getStore() { return this->store; }
