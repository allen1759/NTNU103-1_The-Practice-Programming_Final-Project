#include "UpgradableUnit.h"

CUpgradableUnit::CUpgradableUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price,const size_t upgrade,const std::vector<int>f1)
    :CMapUnit(name,buy,id,numPlayer),price_(price),upgrade_price(upgrade),level_(1)
    {
        for(int i=0,L1 = f1.size();i<L1;i++) {
            travel_fine_.push_back(f1[i]);
        }
    }


//���O���e�^��
    //�g�a���B
size_t CUpgradableUnit::getPrice() const
{
    return price_;
}
    //�L���O
size_t CUpgradableUnit::getFine(const size_t dice) const
{
    return travel_fine_[level_-1];
}
    //�ɯŪ��B
size_t CUpgradableUnit::getUp_price () const
{
    return upgrade_price;
}

//���O���e���

//���A���
    //��X
void CUpgradableUnit::NewHost(CPlayer *P1)
{
    host_ = P1;
    buyable_ = false;
    level_ = 1;
}
    //�D�H�}��
void CUpgradableUnit::bankrupt()
{
    level_ = 1;
    buyable_ = true;
}
