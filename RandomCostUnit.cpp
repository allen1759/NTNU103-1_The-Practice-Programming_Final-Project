#include "RandomCostUnit.h"

//���O���e�^��
    //�g�a���B
size_t CRandomCostUnit::getPrice() const
{
    return price_;
}
    //�L���O(�ݶǤJ�I��)
size_t CRandomCostUnit::getFine(const size_t dice) const
{
    return dice * ( travel_fine_ );
}

//���O���e���
//���A���
    //��X
void CRandomCostUnit::NewHost(CPlayer *P1)
{
    host_ = P1;
    buyable_ = false;
    return;
}
    //�D�H�}��
void CRandomCostUnit::bankrupt()
{
    host_ = nullptr;
    buyable_ = true;
}


