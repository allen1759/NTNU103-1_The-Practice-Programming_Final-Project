#include "RandomCostUnit.h"

//���O���e�^��
    //�g�a���B
size_t CRandomCostUnit::price() const
{
    return price_;
}
    //�L���O(�ݶǤJ�I��)
size_t CRandomCostUnit::fine(const size_t point) const
{
    return point * ( 0.1 * price_ );
}
    //�D�Hid
size_t CRandomCostUnit::MyHost_() const
{
    return host_;
}

//���O���e���
    //�D�H����
bool CRandomCostUnit::isHostRight(const size_t id) const
{
    return ( host_ == id );
}
//���A���
    //��X
void CRandomCostUnit::NewHost(const size_t id)
{
    host_ = id;
    buyable_ = false;
    return;
}
    //�D�H�}��
void CRandomCostUnit::bankrupt()
{
    buyable_ = true;
    return;
}
