#include "RandomCostUnit.h"

//���O���e�^��
    //�g�a���B
size_t CRandomCostUnit::getPrice() const
{
    return price_;
}
    //�L���O(�ݶǤJ�I��)
size_t CRandomCostUnit::getFine(size_t point) const
{
    return point * ( 0.1 * price_ );
}

//���O���e���
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
}


