#include "UpgradableUnit.h"

//���O���e�^��
    //�g�a���B
size_t CUpgradableUnit::getPrice() const
{
    return price_;
}
    //�L���O
size_t CUpgradableUnit::getFine() const
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
void CUpgradableUnit::NewHost(const size_t id)
{
    host_ = id;
    buyable_ = false;
}
    //�D�H�}��
void CUpgradableUnit::bankrupt()
{
    level_ = 1;
    buyable_ = true;
}
