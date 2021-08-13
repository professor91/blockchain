// #include<iostream>
// #include"Blockchain.h"

#include<vector>
#include"Block.h"

//class for complete blockchain
class Blockchain
{
    public:
            //constructor
            Blockchain();
            //function to add a block to the blockchain
            void AddBlock(Block bNew);
            //destructor
            ~Blockchain();

    private:
            int _nDifficulty;                       //difficulty of the mining
            std:: vector<Block> _vChain;            //blockchain

            //function to get previous block
            Block _GetLastBlock() const;
};


Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "Genesis Block"));        //first block of the chain
    _nDifficulty= 6;                                        //setting difficulty of mining
}

Blockchain::~Blockchain()
{
    //destructor
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash= _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}