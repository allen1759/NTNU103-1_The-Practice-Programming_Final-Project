#include "CollectableUnit.h"

//���O���e�^��
    //�g�a���B
size_t CCollectableUnit::price() const
{
    return price_;
}
    //�L���O
size_t CCollectableUnit::fine(const size_t C_Unit) const
{
    return C_Unit * travel_fine_;
}
    //�D�Hid
size_t CCollectableUnit::MyHost_() const
{
    return host_;
}

//���O���e���
    //�D�H����
bool CCollectableUnit::isHostRight(const size_t id) const
{
    return ( id == host_ );
}
//���A���
    //��X
void CCollectableUnit::NewHost(const size_t id)
{
    host_ = id;
    buyable_ = false;
}
    //�D�H�}��
void CCollectableUnit::bankrupt()
{
    buyable_ = true;
}
