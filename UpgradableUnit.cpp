#include "UpgradableUnit.h"

//���O���e�^��
    //�g�a���B
size_t CUpgradableUnit::price() const
{
    return price_;
}
    //�L���O
size_t CUpgradableUnit::fine() const
{
    return ( price_*0.1 ) * level_;
}
    //�ɯŪ��B
size_t CUpgradableUnit::up_price () const
{
    return upgrade_price;
}
    //�D�Hid (-1��L�D�a)
size_t CUpgradableUnit::MyHost_() const
{
    return host_;
}
//���O���e���
    //�D�H����
bool CUpgradableUnit::isHostRight(const size_t id) const
{
    return ( id == host_ );
}
//���A���
    //��X
    //�D�H�}��
void CUpgradableUnit::bankrupt()
{
    host_ = -1;
    level_ = 1;
}
