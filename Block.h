#include<iostream>
// #include<cstdint>
#include<vector>

#include"sha256.h"
#include<string>
#include<sstream>

//class for each block
class Block
{
    public:
            std:: string sPrevHash;                         //string to store hash of previous block
            
            //constructor
            Block(int nIndenIn, const std::string &sDataIn);
            //destructor
            ~Block();
            //function to get the hash of the block
            std:: string GetHash();
            //function to mine the block
            void MineBlock(int nDifficulty);

    private:
            int _nIndex;                                    //integer variable to store the block number/index
            int _nNonce;                                    //
            std:: string _sData;                            //
            std:: string _sHash;                            //string to store the hash of the block
            time_t _tTime;                                  //variable to store time when the block was made
            //function to calculate hash of the block
            std:: string _CalculateHash() const;          
};


Block::Block(int nIndexIn, const std:: string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce= -1;
    _tTime = time(nullptr);
}

Block::~Block()
{
    //destructor
}

std:: string Block::GetHash()
{
    return _sHash;
}

void Block::MineBlock(int nDifficulty)
{
    char cstr[nDifficulty + 1];
    
    for(int i= 0; i< nDifficulty; ++i)
        cstr[i]= '0';
    
    cstr[nDifficulty]= '\0';

    std:: string str(cstr);
    
    do
    {
        _nNonce++;
        _sHash= _CalculateHash();
    }while(_sHash.substr(0, nDifficulty) != str);

    std:: cout << "Block Mined: " << _sHash << std:: endl;        
}

inline std:: string Block::_CalculateHash() const
{
    std:: stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}

