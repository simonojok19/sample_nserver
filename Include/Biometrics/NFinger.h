#ifndef N_FINGER_H_INCLUDED
#define N_FINGER_H_INCLUDED

#include <Biometrics/NFrictionRidge.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFinger, NFrictionRidge)

NResult N_API NFingerCreate(HNFinger * phFinger);
NResult N_API NFingerGetWrongHandWarning(HNFrictionRidge hFrictionRidge, NBool * pValue);
NResult N_API NFingerSetWrongHandWarning(HNFrictionRidge hFrictionRidge, NBool value);

#ifdef N_CPP
}
#endif

#endif // !N_FINGER_H_INCLUDED
